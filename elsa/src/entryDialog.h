#ifndef __enteryDialog__h
#define __enteryDialog__h

#include <iostream>
#include <gtkmm.h>

class EntryDialog:public Gtk::MessageDialog
{
  public:
    EntryDialog(Gtk::Window &parent,
       const Glib::ustring &message,
       bool use_markup=false,
       Gtk::MessageType type=Gtk::MESSAGE_OTHER,
       Gtk::ButtonsType buttons=Gtk::BUTTONS_OK,
       bool modal=false
     );
    void set_text (const Glib::ustring& text);
    Glib::ustring get_text () const;
  private:
    Gtk::Entry *entry;
};
#endif
