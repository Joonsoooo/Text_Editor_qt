#pragma once
#include <QObject>
#include <QMenu>

#include "pch.h"

struct tab_info;

class q_menus : public QObject
{
	Q_OBJECT

public:
	q_menus(MENU_TYPE type = NONE, QWidget* parent = nullptr) : QObject(parent)
	{
	}

	q_menus(tab_info* tab, MENU_TYPE type = NONE, QWidget* parent = nullptr);

	~q_menus();

	void create_menu(tab_info* tab, MENU_TYPE type);

private slots:
	void save_action();

private:
	QMenu* m_menu;

	tab_info* m_tab_info;
};

