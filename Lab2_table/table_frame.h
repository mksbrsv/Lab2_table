#pragma once
#include <wx/wx.h>
#include "table.h"
#include <wx/grid.h>
class table_frame : public wxFrame {
public:
	table_frame(const wxString& title, const wxPoint& position, const wxSize& size);
private:
	//Fields
	table<int, std::string> m_table;
	wxPanel* m_panel = nullptr;
	wxButton* m_button_add = nullptr;
	wxButton* m_button_remove = nullptr;
	wxButton* m_button_find = nullptr;
	wxMenuBar* m_menu_bar = nullptr;
	wxGrid* m_grid = nullptr;

	//Member functions
	void update_grid();
	
	//Events
	void click_add(wxCommandEvent& event);
	void click_remove(wxCommandEvent& event);
	void click_find(wxCommandEvent& event);

	void click_new(wxCommandEvent& event);
	void click_save(wxCommandEvent& event);
	void click_load(wxCommandEvent& event);
	void click_exit(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};

