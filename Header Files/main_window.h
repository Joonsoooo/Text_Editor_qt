#pragma once

#include <QtWidgets/QMainWindow>
#include <QString>
#include <vector>

#include "ui_main_window.h"

using namespace std;

class text_model;
class save_load_handler;
class QPushButton;
class QTextEdit;

struct tab_info
{
    /*text_model* model;
	QPushButton* tab_btn;
    QTextEdit* text_ed;
    int index;*/

    text_model* model;
	QTextEdit* text_ed;
};

class main_window : public QMainWindow
{
    Q_OBJECT

public:
    main_window(QWidget *parent = nullptr);
    ~main_window();

public:
    void load_act();

    QStringList multi_selection_file();
    vector<QString> get_file_list(QStringList files);

    void create_tab_info(text_model* model);
    QPushButton* create_tab_btn();

	text_model* file_to_model(const QString& file_path);
    
private slots:
	void tab_change(int index);


private:
    vector<tab_info*> m_tab_list;
	save_load_handler* m_save_load_hndlr;
    QTabWidget* m_tab_wid;

    int m_selected;

private:
    Ui::main_windowClass m_ui;

};