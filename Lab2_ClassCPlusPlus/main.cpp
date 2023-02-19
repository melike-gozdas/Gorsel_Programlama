#include <iostream>

using namespace std;

class Calisan
{
public:
    string ad;
    int yas;
    Calisan(string ad, int yas)
    {

        this->ad=ad;
        this->yas=yas;
    }
    void BilgileriYazdir()
    {
        cout << "Ad: "<<ad<< " Yas: "<<yas<<endl;
    }
    virtual void YapilanIs()
    //virtual koymamızın sebebi bu metodun soyut bir metot olduğunu yani diğer sınıflarda bu metot bilgilerinin yenilenip yenilenmediğinin (override) kontrol etmesini sağlar.
    {
        cout<<ad<<" mailleri cevaplar ve telefonlara bakar."<<endl;

    }
};

class Yazilimci:public Calisan  //public Calisan yazmazsak Calisan sınıfı nesnelerine ulaşamam.
{
public:
    string kd;
    Yazilimci(string ad, int yas, string kd) : Calisan(ad, yas)
    {
        this->kd=kd;
    }
    void HatayiCoz()
    {
        cout<<ad<< " hatalari "<<kd<< " kullanarak cozer."<<endl;
    }
    //yapılan iş metodu burada override edilmezse calisan sınıfının yapılan iş metodu çalışır.
    void YapilanIs()
    {
        cout<<ad<<" "<<kd<<" dilini kullanarak kodlama yapar."<<endl;

    }
};

class Egitmen:public Calisan
{
public:
    string ve;
    Egitmen(string ad, int yas, string ve):Calisan(ad,yas)
    {
        this->ve=ve;
    }
    void EgitimeHazirlan()
    {
        cout<<ad<< " verecegi "<<ve<<" egitimine hazirlanir."<<endl;
    }
    void YapilanIs()
    {
        cout<<ad<<" "<<ve<<" egitimini verir."<<endl;

    }
};

int main()
{
    Calisan c=Calisan("Ali", 30);
    c.BilgileriYazdir();
    cout<<endl;

    Yazilimci y=Yazilimci("Ayse",35,"C++");
    y.BilgileriYazdir();
    y.HatayiCoz();
    cout<<endl;

    Egitmen e=Egitmen("Seda",20,"ilk yardim");
    e.EgitimeHazirlan();
    cout<<endl;


    c.YapilanIs();
    y.YapilanIs();
    e.YapilanIs();
    cout<<endl;


    Calisan *c1=&y;
    Calisan *c2=&e;

    c1->YapilanIs();
    c2->YapilanIs();


}
