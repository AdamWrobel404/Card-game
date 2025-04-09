#include "cards.h"

cards::cards(int Attack,int Armor,int Heal,bool Refresh, bool Round, int Trucizna, const wxString& obrazFileName)
{
    attack=Attack;
    armor=Armor;
    refresh=Refresh;
    heal=Heal;
    round=Round;
    trucizna=Trucizna;
    wxImage img(obrazFileName, wxBITMAP_TYPE_ANY);
        img.Rescale(2, 1);
        obraz = wxBitmap(img);
}


int const cards::GetAttack()
{
    return attack;
}

int cards::GetArmor()
{
    return armor;
}

int cards::GetHeal()
{
    return heal;
}

bool cards::GetRefresh()
{
    return refresh;
}

bool cards::GetRound()
{
    return round;
}

int cards::GetTrucizna()
{
    return trucizna;
}
