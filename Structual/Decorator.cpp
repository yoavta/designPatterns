#include <string>
#include <iostream>

class DataSource{
public:
    virtual void writeData(std::string data)=0;
    virtual std::string readData()=0;
};


class FileDataSource: public DataSource{
protected:
    std::string _data;
    std::string _name;
public:
    FileDataSource(std::string name){
        _name=name;
    }
    virtual void writeData(std::string data){
        _data = data;
    };
    virtual std::string readData(){
        return _data;
    };
};

class DataSourceDecorator: public DataSource{
protected:
    DataSource* _dataSource;
public:
    DataSourceDecorator(DataSource* dataSource){
        _dataSource=dataSource;
    }
    virtual void writeData(std::string data)=0;
    virtual std::string readData()=0;
};

class CaesarCipherPlus:public DataSourceDecorator{
public:
    CaesarCipherPlus(DataSource* dataSource): DataSourceDecorator(dataSource){};
    virtual void writeData(std::string data){
     _dataSource->writeData(data);
    }
    virtual std::string readData(){
//        std::string c_Cipher(const std::string& input, int Key)
            std::string input =_dataSource->readData();
            std::string retVal = "";
            int Key = 1;
        for(const auto& ch : input)
        {
            if((ch+Key) > 'z')
                retVal += ('a' + (ch+Key) - 'z' - 1);
            else
                retVal += (ch+Key);
        }
            return retVal;
    }

};

class CaesarCipherMinus:public DataSourceDecorator{
public:
    CaesarCipherMinus(DataSource* dataSource): DataSourceDecorator(dataSource){};
    virtual void writeData(std::string data){
        _dataSource->writeData(data);
    }
    virtual std::string readData(){
//        std::string c_Cipher(const std::string& input, int Key)
        std::string input =_dataSource->readData();
        std::string retVal = "";
        int Key = -1;
        for(const auto& ch : input)
        {
            if((ch+Key) > 'z')
                retVal += ('a' + (ch+Key) - 'z' - 1);
            else
                retVal += (ch+Key);
        }
        return retVal;
    }

};

int main(){
    DataSource* dataSource =new CaesarCipherMinus( new CaesarCipherPlus(new FileDataSource("mypc/asasd")));
    dataSource->writeData("shalom kita alef");
    std::cout<<dataSource->readData();

    return 1;
}