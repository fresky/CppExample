#include <cereal/archives/xml.hpp>
#include <fstream>

void Serialization()
{
    {
        std::ofstream os("data.xml");
        cereal::XMLOutputArchive archive(os);

        int Age = 30;
        string str = "Dawei";

        archive(CEREAL_NVP(Age), cereal::make_nvp("Name", str));
    }

    {
        std::ifstream is("data.xml");
        cereal::XMLInputArchive archive(is);

        int age;
        string name;

        archive(age, name);
        cout << "Age: " << age << endl << "Name: " << name << endl;
    }
}