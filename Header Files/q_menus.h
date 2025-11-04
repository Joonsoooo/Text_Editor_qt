#pragma once
#include <QObject>
#include <QMenu>

enum MENU_TYPE
{
	NONE = -1,
	TAB = 0,

};

class q_menus : public QObject
{
	Q_OBJECT

public:
	q_menus(QWidget* parent = nullptr, MENU_TYPE type = NONE) : QObject(parent)
	{
		create_menu(type);
	}

	~q_menus() {}

	void create_menu(MENU_TYPE type);

private:
	QMenu* m_menu;
};

