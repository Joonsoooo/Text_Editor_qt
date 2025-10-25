#pragma once

#include <QtWidgets/QMainWindow>
#include <QString>
#include <vector>

#include "ui_main_window.h"

using namespace std;

class text_model;
class save_load_handler;

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

private:
    text_model* m_model;
	save_load_handler* m_save_load_hndlr;

private:
    Ui::main_windowClass m_ui;

};