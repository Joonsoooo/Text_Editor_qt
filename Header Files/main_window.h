#pragma once

#include <QtWidgets/QMainWindow>
#include <QString>
#include <vector>
#include <QPushbutton>
#include <QTextEdit>

#include "ui_main_window.h"
#include "text_model.h"
#include "tab_mgr.h"
#include "singleton.h"
#include "pch.h"

using namespace std;

class main_window : public QMainWindow, public singleton<main_window>
{
    Q_OBJECT

public:
    main_window(QWidget *parent = nullptr);
    ~main_window();

public:
    void load_act();
    void save_act(int selected_tab);

    QStringList multi_selection_file();
    vector<QString> get_file_list(QStringList files);

	text_model* file_to_model(const QString& file_path);
    QTextEdit* txt_to_ed(const QString& text);

    void create_tab_menu(MENU_TYPE type);

private:
    Ui::main_windowClass m_ui;

	tab_mgr* m_tab_mgr;
};

