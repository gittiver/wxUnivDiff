// TODO this could be a simpler list interface
class TableModel {
public:

  class Observer {
  public:
    virtual void itemTextChanged(size_t row,size_t col,const wxString& text) = 0;
    virtual void itemAdded(size_t row) = 0;
    virtual void itemRemoved(size_t row) = 0;
  };

  virtual ~ListCtrlModel(){};

  void addObserver(Observer* observer);
  void removeObserver(Observer* observer);

  virtual size_t size() const = 0;
  virtual size_t getColumnCount() const = 0;
  virtual void getColumnText(size_t col,wxString& text) const = 0;

  virtual void getText(size_t row,size_t col,wxString& text) = 0;
  virtual void setText(size_t row,size_t col,const wxString& text) = 0;

  private:
    std::list<Observer*> observers;
};

