#include "mainwin.h"
#include "entryDialog.h"
#include <sstream>
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
      vbox.pack_start(*v);
    }
    //vbox.show_all();
    dialog.add(vbox);
  }

  set_data(oss.str());
  dialog.show_all();
  */

  while(true)
  {

      //
      std::ostringstream oss;
      //oss << store->desktop(desktop) << "\n\n";
      oss<<"Following options are avilable.\n";
      //set_data(oss.str());
      on_view_peripheral_click();
      if(store->num_options()==0)
      {
        on_view_peripheral_click();
        break;
      }
      else
      {
        std::string option_number;
        option_number=get_string("\nAdd which peripheral (-1 when done)? ");
        int option=get_int(option_number);
        if(option == -1 || option_number=="-1") break;
        int desktop = store->new_desktop();
        try {
            store->add_option(option, desktop);
        } catch(std::exception& e) {
            std::cerr << "#### INVALID OPTION ####\n\n";
        }

        }
  }
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
    double cost= std::stod(prompt);
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
