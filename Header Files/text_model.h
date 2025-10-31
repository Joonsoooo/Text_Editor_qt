#pragma once
#include <string>
#include <QString>

using namespace std;

class text_model
{
public:
	text_model();
	text_model(const QString& text, const string& directory, const string& filename) : m_text(text), m_directory(directory), m_filename(filename), m_is_modified(false)
	{
	}

private:
	QString m_text;
	string m_directory;
	string m_filename;
	bool m_is_modified;

public:
	const QString& get_text() const { return m_text; }
	const string& get_filepath() const { return m_directory; }
	const string& get_filename() const { return m_filename; }
	bool get_is_modified() const { return m_is_modified; }
	
	void set_text(const QString& text) { m_text = text; }
	void set_filepath(const string& filepath) { m_directory = filepath; }
	void set_filename(const string& filename) { m_filename = filename; }
	void set_is_modified(bool modified) { m_is_modified = modified; }
};

