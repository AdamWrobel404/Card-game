#include <wx/wx.h>


using namespace std;

class cards
{
private:
    int attack;
    int armor;
    bool refresh;
    int heal;
    bool round;
    int trucizna;


public:
    cards(int Attack,int Armor,int Heal,bool Refresh, bool Round, int Trucizna, const wxString& obrazFileName);
    ~cards(){};
    const int GetAttack();
    int GetArmor();
    int GetHeal();
    bool GetRefresh();
    bool GetRound();
    int GetTrucizna();
    wxBitmap obraz;


};

