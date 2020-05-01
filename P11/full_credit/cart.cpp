Cart::Cart(std::string customer)_customer{customer}{}
Virtual Cart::~Cart()
{
  for(auto &v: _items)
    delete v;
}
Cart::Cart(const Cart &cart)_customer{cart._customer}
{
  for(auto v:cart._items )
    _items.push_back(new v);
}
Cart::Cart &operator=(const Cart &cart)
{

}
void Cart::add_item(Item &item)
{

}
double Cart::cost()
{

}
iterator Cart::begin()
{
  return _items.begin();
}
iterator Cart::end()
{
  return _items.end();
}
