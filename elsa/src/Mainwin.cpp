#include "Mainwin.h"
Mainwin::Mainwin()
{
  // /////////////////
  // G U I   S E T U P
  // /////////////////
  set_default_size(800,800);
  set_title("ELSA");

  // Put a vertical box container as the Window contents
  Gtk::Box *vbox= Gtk::manage(new GTK::Vbox);
  add(*vbox);
  // /////// ////////////////////////////////////////////////////////////////
  // M E N U
  // Add a menu bar as the top item in the vertical box
  Gtk::MenuBar *menubar=Gtk::manage(new Gtk::MenuBar);
  vbox->pack_start(*menubar,Gtk::PACK_SHRINK, 0);
  // vbox->add(*menubar);
  //     F I L E
  // Create a File menu and add to the menu bar
  Gtk::MenuItem *menuitem_file=Gtk::manage(new Gtk::MenuItem("_File",true));
  menubar->append(*menuitem_file);
  Gtk::Menu *filemenu=Gtk::manage(new Gtk::Menu());
  menuitem_file->set_submenu(*filemenu);

  //   Q U I T
  //Append Quit to the File menu
  Gtk::MenuItem *menuitem_quit= Gtk::manage{new Gtk::MenuItem("Quit", true)};
  menuitem_quit->signal_activate().connect([this]{this->on_quit_click();});
  filemenu->append(*menuitem_quit);

  // V I E W
  //Create a View menu and add to menu bar
  Gtk::MenuItem *menuitem_view= Gtk::manage(new Gtk::MenuItem("_View",true));
  menubar->append(*menuitem_view);
  Gtk::Menu *viewmenu=Gtk::manage(new Gtk::Menu());
  menuitem_view->set_submenu(viewmenu);

  //       CUSTOMER
  //Append view customer to viewmenu
  Gtk::MenuItem *menuitem_view_customer=Gtk::manage(new Gtk::MenuItem("Customer"),true);
  menuitem_view_customer->signal_activate().connect([this]{this->on_view_customer_click();});
  viewmenu->append(*menuitem_view_customer);

  // PERIPHERAL
  //Append view PERIPHERAL to viewmenu
  Gtk::MenuItem *menuitem_view_peripheral=Gtk::manage(new Gtk::Menuitem("Peripheral"),true);
  menuitem_view_peripheral->signal_activate().connect([this]{this->on_view_peripheral_click();});
  viewmenu->append(*menuitem_view_peripheral);

  // DESKTOP
  //Append view desktop to viewmenu
  Gtk::MenuItem *menuitem_view_desktop=Gtk::manage(new Gtk::Menuitem("Desktop"),true);
  menuitem_view_desktop->signal_activate().connect([this]{this->on_view_desktop_click();});
  viewmenu->append(*menuitem_view_desktop);

  // Order
  //Append view order to viewmenu
  Gtk::MenuItem *menuitem_view_order=Gtk::manage(new Gtk::Menuitem("Order"),true);
  menuitem_view_order->signal_activate().connect([this]{this->on_view_order_click();});
  viewmenu->append(*menuitem_view_order);

  // I N S E R T
  //Create a Insert menu and add to MenuBar
  Gtk::Menuitem *menuitem_insert=Gtk::manage(new Gtk::Menuitem("_Insert",true));
  menubar->append(*menuitem_insert);
  Gtk::Menu *insertmenu=Gtk::manage(new Gtk::Menu());
  menuitem_insert->set_submenu(*insertmenu);

  //      CUSTOMER
  //Create a customer to insertmenu
  Gtk::Menuitem *menuitem_insert_customer=Gtk::manage(new Gtk::MenuItem("Customer", true));
  menuitem_insert_customer->signal_activate().connect([this]{this->on_insert_customer_click();});
  insertmenu->append(*menuitem_insert_customer);

  //  PERIPHERAL
  //Create a Peripheral to insertmenu
  Gtk::MenuItem *menuitem_insert_peripheral= Gtk::manage(new Gtk::MenuItem("Peripheral",true));
  menuitem_insert_peripheral->signal_activate().connect([this]{this->on_insert_peripheral_click();});
  insertmenu->append(*menuitem_insert_peripheral);

  // DESKTOP
  //Create a Desktop to insertmenu
  Gtk::Menuitem *menuitem_insert_desktop=Gtk::manage(new Gtk::Menuitem("Desktop",true));
  menuitem_insert_desktop->signal_activate().connect([this]{this->on_insert_desktop_click();});
  insertmenu->append(*menuitem_insert_desktop);

  // Order
  //Create a Order to insertmenu
  Gtk::MenuItem *menuitem_insert_order=Gtk::manage(new Gtk::MenuItem("Order",true));
  menuitem_insert_order->signal_activate().connect([this]{this->on_insert_order_click();});
  insertmenu->append(*menuitem_insert_order);

  // HELP
  // Create a helpmenu and add to menu MenuBar
  Gtk::MenuItem *menuitem_help=Gtk::manage(new Gtk::MenuItem("_Help"),true);
  menubar->append(*menuitem_help);
  Gtk::Menu *helpmenu= Gtk::manage(new Gtk::Menu());
  menuitem_help->set_submenu(*helpmenu);

  // ABOUT
  //create a about to help
  Gtk::MenuItem *menuitem_about=Gtk::manage(new Gtk::Menuitem("About"),true);
  menuitem_about->signal_activate().connect([this]{this->on_about_click();});
  helpmenu->append(*menuitem_about);



}
Mainwin::~Mainwin()
{

}
