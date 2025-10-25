#pragma once
#include <string>

using namespace std;

class text_model
{
public:
	text_model();

private:
	string m_text;
	string m_filepath;
	string m_filename;
	bool m_is_modified;

public:
	const string& get_text() const { return m_text; }
	const string& get_filepath() const { return m_filepath; }
	const string& get_filename() const { return m_filename; }
	bool get_is_modified() const { return m_is_modified; }
	
	void set_text(const string& text) { m_text = text; }
	void set_filepath(const string& filepath) { m_filepath = filepath; }
	void set_filename(const string& filename) { m_filename = filename; }
	void set_is_modified(bool modified) { m_is_modified = modified; }
};

