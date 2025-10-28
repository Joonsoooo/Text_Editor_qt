#include "pch.h"
#include "main_window.h"
#include "text_model.h"
#include "save_load_handler.h"

#include <QFileDialog>
#include <filesystem>
#include <QPushButton>
#include <QTextEdit>

main_window::main_window(QWidget *parent)
    : QMainWindow(parent)
{
    m_ui.setupUi(this);

    connect(m_ui.load_act, &QAction::triggered, this, &main_window::load_act);

	m_save_load_hndlr = new save_load_handler();


    //m_ui.tab_qhlay->setAlignment(Qt::AlignLeft);

}

main_window::~main_window()
{

}

void main_window::load_act()
{
    QStringList files = multi_selection_file();
	vector<QString> file_list = get_file_list(files);

    for (int i = 0; i < file_list.size(); ++i) 
    {
        text_model* model = m_save_load_hndlr->load(file_list[i]);

        create_tab_info(model);
	}
 //   for (auto const& file : file_list) 
 //   {
 //       text_model* model = m_save_load_hndlr->load(file);
	//}

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

    for (const auto& file : files) 
    {
        //cout << file.toLocal8Bit().constData() << endl;

		m_save_load_hndlr->load(file);

		file_list.push_back(file);
    }

    return file_list;
}

void main_window::create_tab_info(text_model* model)
{
    /*QPushButton* tab_btn = create_tab_btn();

    QTextEdit* text_ed = new QTextEdit(this);

	tab_info* new_tab = new tab_info();

	int size = m_tab_list.size();

	new_tab->model = model;
	new_tab->tab_btn = tab_btn;
	new_tab->text_ed = text_ed;
	new_tab->index = size;

	m_tab_list.push_back(new_tab);

    m_ui.tab_qhlay->addWidget(tab_btn);*/

    tab_info* new_tab = new tab_info();

    QTextEdit* text_ed = new QTextEdit(this);

    new_tab->model = model;
	new_tab->text_ed = text_ed;

    // 모델을 텍스트 에디터에 파서

    if (m_tab_list.empty())
    {
        m_tab_wid = new QTabWidget(this);

        m_ui.central_lay->addWidget(m_tab_wid);

        connect(m_tab_wid, SIGNAL(currentChanged(int)), this, SLOT(tab_change(int)));
    }
    
    QString tab_name = "탭" + QString::number(m_tab_list.size() + 1);

    m_tab_wid->addTab(text_ed, tab_name);

    m_tab_list.push_back(new_tab);
}

QPushButton* main_window::create_tab_btn()
{
	QPushButton* tab_btn = new QPushButton(this);

	tab_btn->setText("탭" + QString::number(m_tab_list.size() + 1));
	tab_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    tab_btn->setMaximumWidth(100);

    return tab_btn;
}

text_model* main_window::file_to_model(const QString& file_path)
{

    return new text_model();
}

void main_window::tab_change(int index)
{
	cout << "tab change: " << index << endl;
}