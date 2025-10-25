#include "pch.h"
#include "main_window.h"
#include "text_model.h"
#include "save_load_handler.h"

#include <QFileDialog>

main_window::main_window(QWidget *parent)
    : QMainWindow(parent)
{
    m_ui.setupUi(this);

    connect(m_ui.load_act, &QAction::triggered, this, &main_window::load_act);

	m_model = new text_model();
	m_save_load_hndlr = new save_load_handler();
}

main_window::~main_window()
{

}

void main_window::load_act()
{
    QStringList files = multi_selection_file();
	vector<QString> file_list = get_file_list(files);

    for (auto const& file : file_list) 
    {
        cout << file.toLocal8Bit().constData() << endl;

	}

	//m_save_load_hndlr->load
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
        file_list.push_back(file);
    }

    return file_list;
}
