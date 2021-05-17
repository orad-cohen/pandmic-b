#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <array>
#include "City.hpp"
#include"Color.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;


Board::CityDetails::CityDetails(std::string color, std::string city, std::array<enum City,_MaxConnections> linked){
    
    Disease = StringToColor(color);
    thisCity = StringToCity(city);
    
    for(auto const& link:linked){
        if(link ==City::Empty){break;}
        Adjecent.emplace(link,true);
    }       
    
    InfectionRate =0;
    ResearchFacility = false;
}   
Board::Board(){
    fstream file("cities_map.txt");
    string Line;
    string thisCity;
    string LinkedCity;
    string DiseaseColor;
    Cure.insert({{Color::Black,false},{Color::Blue,false},{Color::Red,false},{Color::Yellow,false}});
    while(getline(file,Line)){
        istringstream readstream{Line};
        readstream >> thisCity;
        readstream >> DiseaseColor;        
        size_t i = 0;
        array<enum City,_MaxConnections>  connected={City::Empty};
        connected.fill(City::Empty);
        
        while(!readstream.eof()){
            readstream >> LinkedCity;            
            connected.at(i)= StringToCity(LinkedCity);
            i++;
        }
        
       

        CityDetails _city{DiseaseColor,thisCity,connected};
        WorldMap.emplace(StringToCity(thisCity),_city);
    }
    
    
    

}
int& Board::operator[](enum City a){
    return WorldMap[a].InfectionRate;
}
void Board::remove_cures(){
    for(auto& it : Cure){
        it.second=false;
    }
}
void Board::remove_stations(){
    for(auto& it : WorldMap){
        it.second.ResearchFacility=false;
    }
}
bool Board::is_clean(){
    bool ans = true;
    for(auto const& theKeyOfMap:WorldMap){
        if(theKeyOfMap.second.InfectionRate != 0 ){
            ans = false;
            return ans;
        }
     }
     return ans;
}
ostream& pandemic::operator<<(ostream& os , Board& board){
 return os;
}


enum Color pandemic::StringToColor(string &color){
    if(color=="Yellow"){
        return Color::Yellow;
    }
    if(color=="Black"){
        return Color::Black;
    }
    if(color=="Red"){
        return Color::Red;
    }
    
    return Color::Blue;
    


}
enum City pandemic::StringToCity(string city){
    

    if(city=="Algiers"){
        return City::Algiers;
    }
    if(city=="Atlanta"){
        return City::Atlanta;
    }
    if(city=="Baghdad"){
        return City::Baghdad;
    }
    if(city=="Bangkok"){
        return City::Bangkok;
    }
    if(city=="Beijing"){
        return City::Beijing;
    }
    if(city=="Bogota"){
        return City::Bogota;}
        
    if(city=="BuenosAires"){
        return City::BuenosAires;}
    
    if(city=="Cairo"){
        return City::Cairo;}
    
    if(city=="Chennai"){
        return City::Chennai;}
    
    if(city=="Chicago"){
        return City::Chicago;}
    
    if(city=="Delhi"){
        return City::Delhi;}
    
    if(city=="Essen"){
        return City::Essen;}
    
    if(city=="HoChiMinhCity"){
        return City::HoChiMinhCity;}
    
    if(city=="HongKong"){
        return City::HongKong;}
    
    if(city=="Istanbul"){
        return City::Istanbul;}
    
    if(city=="Jakarta"){
        return City::Jakarta;}
    
    if(city=="Johannesburg"){
        return City::Johannesburg;}
    
    if(city=="Karachi"){
        return City::Karachi;}
    
    if(city=="Khartoum"){
        return City::Khartoum;}
    
    if(city=="Kinshasa"){
        return City::Kinshasa;}
    
    if(city=="Kolkata"){
        return City::Kolkata;}
    
    if(city=="Lagos"){
        return City::Lagos;}
    
    if(city=="Lima"){
        return City::Lima;}
    
    if(city=="London"){
        return City::London;}
    
    if(city=="LosAngeles"){
        return City::LosAngeles;}
    
    if(city=="Madrid"){
        return City::Madrid;}
    
    if(city=="Manila"){
        return City::Manila;}
    
    if(city=="MexicoCity"){
        return City::MexicoCity;}
    
    if(city=="Miami"){
        return City::Miami;}
    
    if(city=="Milan"){
        return City::Milan;}
    
    if(city=="Montreal"){
        return City::Montreal;}
    if(city=="Moscow"){
        return City::Moscow;
    }
    if(city=="Mumbai"){
        return City::Mumbai;
    }
    if(city=="NewYork"){
        return City::NewYork;
    }
    if(city=="Osaka"){
        return City::Osaka;
    }
    if(city=="Paris"){
        return City::Paris;
    }
    if(city=="Riyadh"){
        return City::Riyadh;
    }
    if(city=="SanFrancisco"){
        return City::SanFrancisco;
    }
    if(city=="Santiago"){
        return City::Santiago;
    }
    if(city=="SaoPaulo"){
        return City::SaoPaulo;
    }
    if(city=="Seoul"){
        return City::Seoul;
    }
    if(city=="Shanghai"){
        return City::Shanghai;
    }
    if(city=="StPetersburg"){
        return City::StPetersburg;
    }
    if(city=="Sydney"){
        return City::Sydney;
    }
    if(city=="Taipei"){
        return City::Taipei;
    }
    if(city=="Tehran"){
        return City::Tehran;
    }
    if(city=="Tokyo"){
        return City::Tokyo;
    }
    
    return City::Washington;
    
   

}
string Board::ColorToString(enum Color color){
     if(color==Color::Yellow){
        return "Yellow";
    }
    if(color==Color::Black){
        return "Black";
    }
    if(color==Color::Red){
        return "Red";
    }
    
    return  "Blue";
    
    



}
string Board::CityToString(enum City city){
    

    if(city==City::Algiers){
        return "Algiers";
    }
    if(city==City::Atlanta){
        return "Atlanta";
    }
    if(city==City::Baghdad){
        return "Baghdad";
    }
    if(city==City::Bangkok){
        return "Bangkok";
    }
    if(city==City::Beijing){
        return "Beijing";
    }
    if(city==City::Bogota){
        return "Bogota";}
        
    if(city==City::BuenosAires){
        return "BuenosAires";}
    
    if(city==City::Cairo){
        return "Cairo";}
    
    if(city==City::Chennai){
        return "Chennai";}
    
    if(city==City::Chicago){
        return "Chicago";}
    
    if(city==City::Delhi){
        return "Delhi";}
    
    if(city==City::Essen){
        return "Essen";}
    
    if(city==City::HoChiMinhCity){
        return "HoChiMinhCity";}
    
    if(city==City::HongKong){
        return "HongKong";}
    
    if(city==City::Istanbul){
        return "Istanbul";}
    
    if(city==City::Jakarta){
        return "Jakarta";}
    
    if(city==City::Johannesburg){
        return "Johannesburg";}
    
    if(city==City::Karachi){
        return "Karachi";}
    
    if(city==City::Khartoum){
        return "Khartoum";}
    
    if(city==City::Kinshasa){
        return "Kinshasa";}
    
    if(city==City::Kolkata){
        return "Kolkata";}
    
    if(city==City::Lagos){
        return "Lagos";}
    
    if(city==City::Lima){
        return "Lima";}
    
    if(city==City::London){
        return "London";}
    
    if(city==City::LosAngeles){
        return "LosAngeles";}
    
    if(city==City::Madrid){
        return "Madrid";}
    
    if(city==City::Manila){
        return "Manila";}
    
    if(city==City::MexicoCity){
        return "MexicoCity";}
    
    if(city==City::Miami){
        return "Miami";}
    
    if(city==City::Milan){
        return "Milan";}
    
    if(city==City::Montreal){
        return "Montreal";}
    if(city==City::Moscow){
        return "Moscow";
    }
    if(city==City::Mumbai){
        return "Mumbai";
    }
    if(city==City::NewYork){
        return "NewYork";
    }
    if(city==City::Osaka){
        return "Osaka";
    }
    if(city==City::Paris){
        return "Paris";
    }
    if(city==City::Riyadh){
        return "Riyadh";
    }
    if(city==City::SanFrancisco){
        return "SanFrancisco";
    }
    if(city==City::Santiago){
        return "Santiago";
    }
    if(city==City::SaoPaulo){
        return "SaoPaulo";
    }
    if(city==City::Seoul){
        return "Seoul";
    }
    if(city==City::Shanghai){
        return "Shanghai";
    }
    if(city==City::StPetersburg){
        return "StPetersburg";
    }
    if(city==City::Sydney){
        return "Sydney";
    }
    if(city==City::Taipei){
        return "Taipei";
    }
    if(city==City::Tehran){
        return "Tehran";
    }
    if(city==City::Tokyo){
        return "Tokyo";
    }
    if(city==City::Washington){
        return "Washington";
    }
    return "Empty";
    
    

}
void Board::Pr(){
    for (auto const& map : WorldMap)
    {
        cout<<CityToString(map.first)<<":"<<endl;
        cout<<"Connected Cities:"<<endl;
        for (auto const & it:map.second.Adjecent)
        {
            cout<<CityToString(it.first)<<endl;
        }
        cout<< endl;
    }
    
    
}


