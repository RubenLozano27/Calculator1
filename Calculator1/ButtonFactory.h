#include "wx/wx.h"
class ButtonFactory
{
public:
	wxButton* BuildButton(wxWindow *_parent,wxString _title,int _Id)
	{
		wxButton* button = new wxButton(_parent, _Id, _title);
		return button;
	}
};