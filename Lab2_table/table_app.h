#pragma once
#include <wx/wx.h>
#include "table_frame.h"
class table_app : public wxApp {
public:
	virtual bool OnInit() override;
private:
	table_frame* frame = nullptr;
};

