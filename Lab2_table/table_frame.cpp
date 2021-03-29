#include "table_frame.h"

wxBEGIN_EVENT_TABLE(table_frame, wxFrame)
EVT_BUTTON(101, table_frame::click_add)
EVT_BUTTON(102, table_frame::click_remove)
EVT_BUTTON(103, table_frame::click_find)
EVT_MENU(201, table_frame::click_new)
wxEND_EVENT_TABLE()

table_frame::table_frame(const wxString& title, const wxPoint& position, const wxSize& size) :
	wxFrame(nullptr, wxID_ANY, title, position, size),
	m_table(10) {

	m_panel = new wxPanel(this, wxID_ANY, this->GetPosition(), this->GetSize());
	// Buttons init
	m_button_add = new wxButton(m_panel, 101, "Add", wxPoint(100, 400));
	const auto add_pos = m_button_add->GetPosition();
	m_button_remove = new wxButton(m_panel, 102, "Remove", wxPoint(add_pos.x + m_button_add->GetSize().GetWidth()*2 , add_pos.y));
	const auto remove_pos = m_button_remove->GetPosition();
	m_button_find = new wxButton(m_panel, 103, "Find", wxPoint(remove_pos.x + m_button_remove->GetSize().GetWidth() * 2, remove_pos.y));

	// Menu init
	m_menu_bar = new wxMenuBar();
	this->SetMenuBar(m_menu_bar);
	auto* menu = new wxMenu();
	menu->Append(201, "New");
	menu->Append(202, "Save");
	menu->Append(203, "Load");
	menu->Append(204, "Exit");
	m_menu_bar->Append(menu, "File");

	// Table init :TODO	fix size of the grid
	m_grid = new wxGrid(m_panel, wxID_ANY, wxPoint(m_button_add->GetPosition().x + (m_button_add->GetSize().GetWidth() / 2), 10), wxSize(300, 350));
	m_grid->CreateGrid(100, 2);
	m_grid->SetColSize(0, 146);
	m_grid->SetColSize(1, 146);
	m_grid->FitInside();
	m_grid->HideRowLabels();
	m_grid->SetColLabelValue(0, "Key");
	m_grid->SetColLabelValue(1, "Value");
	m_grid->EnableEditing(false);
}


void table_frame::update_grid() {
	if (m_table.is_empty()) {
		m_grid->ClearGrid();
		return;
	}
	else {
		m_grid->ClearGrid();
		int row = 0;
		for (m_table.reset(); !m_table.is_end(); m_table.next()) {
			m_grid->SetCellValue(row, 0, wxString(std::to_string(m_table.get_key())));
			m_grid->SetCellValue(row, 1, wxString(m_table.get_value()));
			row++;
		}
		
	}
}

void table_frame::click_add(wxCommandEvent& event) {
	auto* add_dialog = new wxTextEntryDialog(m_panel, "Enter key:value");
	add_dialog->ShowModal();
	const std::string delimiter = ":";
	std::string key_value = add_dialog->GetValue().ToStdString();
	const std::string key = key_value.substr(0, key_value.find(":"));
	key_value.erase(0, key.length() + 1);
	m_table.insert(std::stoi(key), key_value);
	update_grid();
	event.Skip();
}

void table_frame::click_remove(wxCommandEvent& event) {
	auto* remove_dialog = new wxTextEntryDialog(m_panel, "Enter key");
	remove_dialog->ShowModal();
	const std::string key = remove_dialog->GetValue().ToStdString();
	if (m_table.remove(std::stoi(key))) {
		wxMessageBox("Successfully removed");
	}
	else {
		wxMessageBox("There's no this key in the table");
	}
	update_grid();
	event.Skip();
	
}

void table_frame::click_find(wxCommandEvent& event) {
	auto* find_dialog = new wxTextEntryDialog(m_panel, "Enter key");
	find_dialog->ShowModal();
	const std::string key = find_dialog->GetValue().ToStdString();
	auto [success, value] = m_table.find(std::stoi(key));
	if (success) {
		wxMessageBox(wxString("Found: ") + wxString(key) + wxT(" : ") + wxString(value));
	}
	else {
		wxMessageBox("There's no this key in the table");
	}
	event.Skip();
}

void table_frame::click_new(wxCommandEvent& event) {
	m_table = table<int, std::string>(10);
	update_grid();
	event.Skip();
}

void table_frame::click_save(wxCommandEvent& event) {
	event.Skip();
}

void table_frame::click_load(wxCommandEvent& event) {
	event.Skip();
}

void table_frame::click_exit(wxCommandEvent& event) {
	this->Close();
	event.Skip();
}

