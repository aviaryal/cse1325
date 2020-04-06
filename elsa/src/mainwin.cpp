#include "mainwin.h"
#include "entryDialog.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
Mainwin::Mainwin():store{new Store}
{
  // /////////////////
  // G U I   S E T U P
  // /////////////////
  set_default_size(800,800);
  set_title("ELSA");

  // Put a vertical box container as the Window contents
  Gtk::Box *vbox= Gtk::manage(new Gtk::VBox);
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

  //NEW
  //Appen new to the file menu
  Gtk::MenuItem *menuitem_new=Gtk::manage(new Gtk::MenuItem("New", true));
  menuitem_new->signal_activate().connect([this]{this->on_new_store_click();});
  filemenu->append(*menuitem_new);
  //OPEN
  //Append a open to file menu
  Gtk::MenuItem *menuitem_open=Gtk::manage(new Gtk::MenuItem("Open", true));
  menuitem_open->signal_activate().connect([this]{this->on_open_click();});
  filemenu->append(*menuitem_open);
  //Save
  //Appen a save to file menu
  Gtk::MenuItem *menuitem_save=Gtk::manage(new Gtk::MenuItem("Save", true));
  menuitem_save->signal_activate().connect([this]{this->on_save_click();});
  filemenu->append(*menuitem_save);

  //Save_as
  //Appen a save as to file menu
  Gtk::MenuItem *menuitem_save_as=Gtk::manage(new Gtk::MenuItem("Save as", true));
  menuitem_save_as->signal_activate().connect([this]{this->on_save_as_click();});
  filemenu->append(*menuitem_save_as);

  //   Q U I T
  //Append Quit to the File menu
  Gtk::MenuItem *menuitem_quit= Gtk::manage(new Gtk::MenuItem("Quit", true));
  menuitem_quit->signal_activate().connect([this]{this->on_quit_click();});
  filemenu->append(*menuitem_quit);

  // V I E W
  //Create a View menu and add to menu bar
  Gtk::MenuItem *menuitem_view= Gtk::manage(new Gtk::MenuItem("_View",true));
  menubar->append(*menuitem_view);
  Gtk::Menu *viewmenu=Gtk::manage(new Gtk::Menu());
  menuitem_view->set_submenu(*viewmenu);

  //       CUSTOMER
  //Append view customer to viewmenu
  Gtk::MenuItem *menuitem_view_customer=Gtk::manage(new Gtk::MenuItem("Customer",true));
  menuitem_view_customer->signal_activate().connect([this]{this->on_view_customer_click();});
  viewmenu->append(*menuitem_view_customer);

  // PERIPHERAL
  //Append view PERIPHERAL to viewmenu
  Gtk::MenuItem *menuitem_view_peripheral=Gtk::manage(new Gtk::MenuItem("Peripheral",true));
  menuitem_view_peripheral->signal_activate().connect([this]{this->on_view_peripheral_click();});
  viewmenu->append(*menuitem_view_peripheral);

  // DESKTOP
  //Append view desktop to viewmenu
  Gtk::MenuItem *menuitem_view_desktop=Gtk::manage(new Gtk::MenuItem("Desktop",true));
  menuitem_view_desktop->signal_activate().connect([this]{this->on_view_desktop_click();});
  viewmenu->append(*menuitem_view_desktop);

  // Order
  //Append view order to viewmenu
  Gtk::MenuItem *menuitem_view_order=Gtk::manage(new Gtk::MenuItem("Order",true));
  menuitem_view_order->signal_activate().connect([this]{this->on_view_order_click();});
  viewmenu->append(*menuitem_view_order);

  // I N S E R T
  //Create a Insert menu and add to MenuBar
  Gtk::MenuItem *menuitem_insert=Gtk::manage(new Gtk::MenuItem("_Insert",true));
  menubar->append(*menuitem_insert);
  Gtk::Menu *insertmenu=Gtk::manage(new Gtk::Menu());
  menuitem_insert->set_submenu(*insertmenu);

  //      CUSTOMER
  //Create a customer to insertmenu
  Gtk::MenuItem *menuitem_insert_customer=Gtk::manage(new Gtk::MenuItem("Customer", true));
  menuitem_insert_customer->signal_activate().connect([this]{this->on_insert_customer_click();});
  insertmenu->append(*menuitem_insert_customer);

  //  PERIPHERAL
  //Create a Peripheral to insertmenu
  Gtk::MenuItem *menuitem_insert_peripheral= Gtk::manage(new Gtk::MenuItem("Peripheral",true));
  menuitem_insert_peripheral->signal_activate().connect([this]{this->on_insert_peripheral_click();});
  insertmenu->append(*menuitem_insert_peripheral);

  // DESKTOP
  //Create a Desktop to insertmenu
  Gtk::MenuItem *menuitem_insert_desktop=Gtk::manage(new Gtk::MenuItem("Desktop",true));
  menuitem_insert_desktop->signal_activate().connect([this]{this->on_insert_desktop_click();});
  insertmenu->append(*menuitem_insert_desktop);

  // Order
  //Create a Order to insertmenu
  Gtk::MenuItem *menuitem_insert_order=Gtk::manage(new Gtk::MenuItem("Order",true));
  menuitem_insert_order->signal_activate().connect([this]{this->on_insert_order_click();});
  insertmenu->append(*menuitem_insert_order);

  // HELP
  // Create a helpmenu and add to menu MenuBar
  Gtk::MenuItem *menuitem_help=Gtk::manage(new Gtk::MenuItem("_Help",true));
  menubar->append(*menuitem_help);
  Gtk::Menu *helpmenu= Gtk::manage(new Gtk::Menu());
  menuitem_help->set_submenu(*helpmenu);



  Gtk::MenuItem *menuitem_easter = Gtk::manage(new Gtk::MenuItem("_Easter Egg", true));
  menuitem_easter->signal_activate().connect([this] {this->on_easter_egg_click();});
  helpmenu->append(*menuitem_easter);




  // ABOUT
  //create a about to help
  Gtk::MenuItem *menuitem_about=Gtk::manage(new Gtk::MenuItem("About",true));
  menuitem_about->signal_activate().connect([this]{this->on_about_click();});
  helpmenu->append(*menuitem_about);

  // /////////////////////////// ////////////////////////////////////////////
  //    D I S P L A Y the data
  // Provide a text entry box to show the data
  data = Gtk::manage(new Gtk::Label{"",Gtk::ALIGN_START,Gtk::ALIGN_START});
  data->set_hexpand(true);
  data->set_vexpand(true);
  vbox->add(*data);

  ///////////////////////////////////////////////////////////////////////
  //Provide a status bar
  msg = Gtk::manage(new Gtk::Label());
  msg->set_hexpand(true);
  vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
  //vbox->add(*msg);




  vbox->show_all();
}
Mainwin::~Mainwin()
{

}





void Mainwin::on_easter_egg_click() {
    Customer c{"Bugs Bunny", "817-ACA-RROT", "bugs@loony.tunes"};          store->add_customer(c);
    c = Customer{"Elastigirl", "817-STR-ETCH", "helen@incredibles.movie"}; store->add_customer(c);
    c = Customer{"Tuck and Roll", "817-UFI-RED2", "circus@bugs.life"};     store->add_customer(c);
    c = Customer{"Tiana", "817-NOG-RIMM", "princess@lily.pad"};            store->add_customer(c);

    Options o{"CPU: 2.6 GHz Xeon 6126T", 2423.47};         store->add_option(o);
    o = Options{"CPU: 2.4 GHz Core i7-8565U", 388.0};      store->add_option(o);
    o = Options{"CPU: 2.2 GHz AMD Opteron", 37.71};        store->add_option(o);
    o = Options{"CPU: 300 MHz AM3351BZCEA30R ARM", 11.03}; store->add_option(o);
    o = Options{"CPU: 240 MHz ColdFire MCF5", 17.33};      store->add_option(o);

    o = Options{"2 GB RAM", 17.76};                        store->add_option(o);
    o = Options{"4 GB RAM", 22.95};                        store->add_option(o);
    o = Options{"8 GB RAM", 34.99};                        store->add_option(o);
    o = Options{"16 GB RAM", 92.99};                       store->add_option(o);
    o = Options{"32 GB RAM", 134.96};                      store->add_option(o);
    o = Options{"64 GB RAM", 319.99};                      store->add_option(o);

    o = Options{"0.5 TB SSD", 79.99};                      store->add_option(o);
    o = Options{"1 TB SSD", 109.99};                       store->add_option(o);
    o = Options{"2 TB SSD", 229.99};                       store->add_option(o);
    o = Options{"4 TB SSD", 599.99};                       store->add_option(o);

    o = Options{"1 TB PC Disk", 44.83};                    store->add_option(o);
    o = Options{"2 TB Hybrid Disk", 59.99};                store->add_option(o);
    o = Options{"4 TB Hybrid Disk", 93.98};                store->add_option(o);

    int desktop = store->new_desktop();
    store->add_option(0, desktop);
    store->add_option(9, desktop);
    store->add_option(14, desktop);

    desktop = store->new_desktop();
    store->add_option(1, desktop);
    store->add_option(7, desktop);
    store->add_option(17, desktop);

    desktop = store->new_desktop();
    store->add_option(5, desktop);
    store->add_option(7, desktop);
    store->add_option(15, desktop);
}



void Mainwin::on_new_store_click()
{
 delete store;
 on_view_customer_click();
}
void Mainwin::on_open_click()
{
  Gtk::FileChooserDialog dialog("Please choose a file",Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
  dialog.set_transient_for(*this);

  auto filter_nim = Gtk::FileFilter::create();
  filter_nim->set_name("elsa files");
  filter_nim->add_pattern("*.elsa");
  dialog.add_filter(filter_nim);

  auto filter_any = Gtk::FileFilter::create();
  filter_any->set_name("Any files");
  filter_any->add_pattern("*");
  dialog.add_filter(filter_any);

  dialog.set_filename("untitled.elsa");

  //Add response buttons the the dialog:
  dialog.add_button("_Cancel", 0);
  dialog.add_button("_Open", 1);
  int result = dialog.run();
  if (result == 1) {
      try
      {
          delete store;
          _filename=dialog.get_filename();
          std::ifstream ifs{dialog.get_filename()};
          store = new Store{ifs};

          if(!ifs) throw std::runtime_error{"File contents bad"};

      } catch (std::exception& e)
      {
          Gtk::MessageDialog{*this, "Unable to open file"}.run();
          delete store;
      }
  }
}
void Mainwin::on_save_click()
{
  if(_filename.empty())
    on_save_as_click();
  else
  {
    try
    {
        std::ofstream ofs{_filename};
        store->save(ofs);
        if(!ofs) throw std::runtime_error{"Error writing file"};
    } catch(std::exception& e) {
        Gtk::MessageDialog{*this, "Unable to save file: "}.run();
    }
  }
}
void Mainwin::on_save_as_click()
{
  Gtk::FileChooserDialog dialog("Please choose a file",
        Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
  dialog.set_transient_for(*this);

  auto filter_nim = Gtk::FileFilter::create();
  filter_nim->set_name("Elsa files");
  filter_nim->add_pattern("*.elsa");
  dialog.add_filter(filter_nim);

  auto filter_any = Gtk::FileFilter::create();
  filter_any->set_name("Any files");
  filter_any->add_pattern("*");
  dialog.add_filter(filter_any);

  dialog.set_filename("untitled.elsa");

  //Add response buttons the the dialog:
  dialog.add_button("_Cancel", 0);
  dialog.add_button("_Save", 1);

  int result = dialog.run();

  if (result == 1) {
      try
      {
          _filename=dialog.get_filename();
          std::ofstream ofs{dialog.get_filename()};
          store->save(ofs);
          //ofs << computer_player->get_active() << std::endl;
          if(!ofs) throw std::runtime_error{"Error writing file"};
      } catch(std::exception& e) {
          Gtk::MessageDialog{*this, "Unable to save file: "}.run();
      }
  }
}


void Mainwin::on_quit_click()
{
  close();
}
void Mainwin::on_view_customer_click()
{
  std::ostringstream oss;
  if(store->num_customers()==0)
    oss<<"Sorry, No customer \n";
  else
  {
    for(int i=0;i <store->num_customers();i++)
      oss<< i << ") " << store->customer(i) << "\n";
  }
  set_data(oss.str());
}

void Mainwin::on_view_peripheral_click()
{
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2);
  if(store->num_options()==0)
    oss<<"No Options \n";
  else
  {
    for(int i=0;i <store->num_options();i++)
      oss<< i << ") " << store->option(i) << "\n";
  }
  set_data(oss.str());
}

void Mainwin::on_view_desktop_click()
{
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2);
  if(store->num_desktops()==0)
    oss<<"No desktop \n";
  else
  {
    for(int i=0;i <store->num_desktops();i++)
      oss<< i << ") " << store->desktop(i) << "\n";
  }

  set_data(oss.str());
}
void Mainwin::on_view_order_click()
{
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2);
  if(store->num_orders()==0)
    oss<<"No order \n";
  else
  {
    for(int i=0;i <store->num_orders();i++)
      oss<< i << ") " << store->order(i) << "\n";
  }
  set_data(oss.str());

}
void Mainwin::on_insert_peripheral_click()
{
  std::string option_name, option_cost;
  do
  {
    if(option_name.empty())
    {
      option_name=get_string("Type the pheripheral");
      continue;
    }
    else if(option_cost.empty())
    {
      option_cost=get_string("What is the cost?");
      continue;
    }
  }
  while(option_name.empty() || option_cost.empty());
  double cost=get_double(option_cost);
  Options option{option_name,cost};
  store->add_option(option);
  set_msg("Added Option: "+ option_name);
  on_view_peripheral_click();
}
void Mainwin::on_insert_desktop_click()
{
  /*
  Gtk::Dialog dialog{"Options", *this};
  std::vector<Gtk::CheckButton * >checkbutton;
  std::ostringstream oss;

  if(store->num_options()==0)
    oss<<"No Options \n";
  else
  {
    for(int i=0;i <store->num_options();i++)
    {
      oss<< i << ") " << store->option(i) << "\n";
      //set_data(oss.str());
      checkbutton.push_back(Gtk::manage(new Gtk::CheckButton{oss.str()}));

    }
    Gtk::VBox vbox;
    for(auto v: checkbutton)
    {
      //vbox.pack_start(*v);
      dialog.add(*v);
    }
    //vbox.show_all();
    //dialog.add(vbox);
  }

  set_data(oss.str());
  dialog.show_all();
  dialog.run();
  */

  on_view_peripheral_click();
  int desktop = store->new_desktop();
  while(true && store->num_options()>0)
  {
      std::ostringstream oss;
      std::string option_number;
      oss << store->desktop(desktop) << "\nAdd which peripheral (-1 when done)? ";
      option_number=get_string(oss.str());
      if(option_number.empty()) continue;
      int option=get_int(option_number);
      if(option == -1 || option_number=="-1")
        break;
      try {
          store->add_option(option, desktop);
          set_msg("Added desktop " + std::to_string(desktop));

      } catch(std::exception& e) {
          Gtk::MessageDialog{*this, "#### INVALID OPTION ####\n\n"}.run();
      }
  }
  //*/
  on_view_desktop_click();

}
void Mainwin::on_insert_order_click()
{
  std::ostringstream oss;

  if(store->num_customers()==0)
    on_view_customer_click();
  else
  {
    if(store->num_customers()==0)
      on_view_customer_click();
    std::string customer_no=get_string( "Customer? ");
    int customer=get_int(customer_no);
    int order = store->new_order(customer);

    while(true) {

        if(store->num_desktops()==0)
        {
          on_view_desktop_click();
          break;
        }
        else
        {
          on_view_desktop_click();
          std::string desktop_no=get_string("Desktop (-1 when done)? ");
          int desktop=get_int(desktop_no);
          //std::cin >> desktop; std::cin.ignore(32767, '\n');
          if(desktop == -1 || desktop_no=="-1") break;
          store->add_desktop(desktop, order);
        }
    }
    set_msg("\n++++ Order Placed ++++ \n");
  }
  on_view_order_click();
}
void Mainwin::on_insert_customer_click()
{

  std::string name, email, phoneno;
  do
  {
    if(name.empty())
    {
      name=get_string("What is the customer name??");
      continue;
    }
    else if(email.empty())
    {
      email=get_string("What is the email?");
      continue;
    }
    else if(phoneno.empty())
    {
      phoneno=get_string("What is the phoneno?");
      continue;
    }
  } while(name.size()==0 || email.empty() || phoneno.empty());
  Customer customer{name, phoneno, email};
  store->add_customer(customer);
  set_msg("Added Customer: "+name);
  on_view_customer_click();
}
void Mainwin::on_about_click()
{
  Gtk::AboutDialog dialog;
  dialog.set_transient_for(*this); // Avoid the discouraging warning
  dialog.set_program_name("ELSA");
  //auto logo = Gdk::Pixbuf::create_from_file("128px-Pyramidal_matches.png");
  //dialog.set_logo(logo);
  dialog.set_version("Version 1.2.1");
  dialog.set_copyright("Copyright 2020");
  dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
  std::vector< Glib::ustring > authors = {"Avinash Aryal"};
  dialog.set_authors(authors);

  dialog.run();
}
std::string Mainwin::get_string(std::string prompt)
{

  EntryDialog edialog{*this,prompt, true};
  //edialog.set_secondary_text("What <i>shall</i> we display <b>today</b>?", true);
  //edialog.set_text("Nothing to report...");
  edialog.run();

  //Gtk::MessageDialog mdialog{*this, edialog.get_text()};
  //mdialog.run();
  return edialog.get_text();

  //return prompt;
}
double Mainwin::get_double(std::string prompt)
{
  try
  {
    double cost= std::stod(prompt);
    return cost;
  }
  catch (std::invalid_argument const &e)
  {
    std::cout<<"Bad input\n";
  }
  catch(std::out_of_range const &e)
  {
    std::cout<<"Integer Overflow \n";
  }
}
int Mainwin::get_int(std::string prompt)
{
  try
  {
    int cost= std::stoi(prompt);
  }
  catch (std::invalid_argument const &e)
  {
    std::cout<<"Bad input\n";
  }
  catch(std::out_of_range const &e)
  {
    std::cout<<"Integer Overflow \n";
  }
}
void Mainwin::set_data(std::string s)
{
  data->set_text(s);
}
void Mainwin::set_msg(std::string s)
{
  msg->set_text(s);
}
