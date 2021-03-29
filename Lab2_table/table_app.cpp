#include "table_app.h"

wxIMPLEMENT_APP(table_app);

bool table_app::OnInit() {
	frame = new table_frame("Table", wxPoint(50, 50), wxSize(600, 500));
	frame->Show();
	return true;
}
