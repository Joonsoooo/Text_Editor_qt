#pragma once

#include <QtWidgets/QMainWindow>
#include <QString>
#include <vector>

#include "ui_main_window.h"

using namespace std;

class text_model;
class save_load_handler;
class QPushButton;

struct tab_info
{
    text_model* model;
	QPushButton* tab_btn;
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

    void add_tab(text_model* model);
    QPushButton* create_tab_btn();

	text_model* file_to_model(const QString& file_path);

private:
    vector<tab_info*> m_tab_list;
	save_load_handler* m_save_load_hndlr;

private:
    Ui::main_windowClass m_ui;

};