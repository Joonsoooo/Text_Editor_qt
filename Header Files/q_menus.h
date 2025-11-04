#pragma once
#include <QObject>
#include <QMenu>

enum MENU_TYPE
{
	NONE = -1,
	TAB = 0,

};

template<typename T>
class q_menus : public QObject
{
	Q_OBJECT

public:
	q_menus(QWidget* parent = nullptr, MENU_TYPE type = NONE, T data) : QObject(parent)
	{
		create_menu(type, data);
	}

	~q_menus() {}

	void create_menu(MENU_TYPE type, T* data);

	void save();

private:
	QMenu* m_menu;

	T* m_curr_data;
};

