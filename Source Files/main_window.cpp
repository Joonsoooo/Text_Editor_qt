#include "pch.h"
#include "main_window.h"
#include "text_model.h"
#include "save_load_handler.h"

#include <QFileDialog>
#include <filesystem>
#include <QPushButton>
#include <QTextEdit>
#include <QTabbar.h>

main_window::main_window(QWidget *parent)
    : QMainWindow(parent)
{
    m_ui.setupUi(this);

    connect(m_ui.load_act, &QAction::triggered, this, &main_window::load_act);
    connect(m_ui.save_act, &QAction::triggered, this, &main_window::save_act);

	m_tab_mgr = new tab_mgr(this);
}

main_window::~main_window()
{
    delete m_tab_mgr;
}

void main_window::load_act()
{
    QStringList files = multi_selection_file();
	vector<QString> file_list = get_file_list(files);

	save_load_handler* save_load_hndl = new save_load_handler();

    for (int i = 0; i < file_list.size(); ++i) 
    {
        text_model* model = save_load_hndl->load(file_list[i]);

        if (false == m_tab_mgr->get_tab_list().size())
        {
            m_ui.central_lay->addWidget(m_tab_mgr->get_tab_widget());
		}

        m_tab_mgr->create_tab_info(model);

        m_tab_mgr->get_tab_list()[i]->text_ed->setText(model->get_text());
	}

    delete save_load_hndl;
}

void main_window::save_act(int selected_tab)
{
    if (m_tab_mgr->get_tab_list().empty())
    {
        // 예외 코드
    }
    else
    {
        text_model* model = m_tab_mgr->get_tab_list()[selected_tab]->model;

        QTextEdit* text_ed = (QTextEdit*)(m_tab_mgr->get_tab_widget()->currentWidget());

        if (text_ed) 
        {
            QString text = text_ed->toPlainText();

			model->set_text(text);

            save_load_handler* save_load_hndl = new save_load_handler();

            save_load_hndl->save(model);

            delete save_load_hndl;
        }
        else
        {
			// 예외 코드

        }
    }
}

QStringList main_window::multi_selection_file()
{
    QStringList files = QFileDialog::getOpenFileNames(
        this,
        tr("파일 선택"),
        "",
        tr("텍스트 파일 (*.txt);;모든 파일 (*.*)")
    );


    return files;
}

vector<QString> main_window::get_file_list(QStringList files)
{
    vector<QString> file_list;

    file_list.reserve(files.size());

    save_load_handler* save_load_hndl = new save_load_handler();

    for (const auto& file : files) 
    {
        //cout << file.toLocal8Bit().constData() << endl;

        save_load_hndl->load(file);

		file_list.push_back(file);
    }

	delete save_load_hndl;

    return file_list;
}

text_model* main_window::file_to_model(const QString& file_path)
{

    return new text_model();
}

QTextEdit* main_window::txt_to_ed(const QString& text)
{
	QTextEdit* text_ed = new QTextEdit(this);

	text_ed->setText(text);

    return text_ed;
}

void main_window::create_tab_menu(MENU_TYPE type)
{

}
