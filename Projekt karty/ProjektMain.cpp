/***************************************************************
 * Name:      ProjektMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Mateusz Wrzosek ()
 * Created:   2023-12-13
 * Copyright: Mateusz Wrzosek ()
 * License:
 **************************************************************/

#include "ProjektMain.h"
#include <wx/msgdlg.h>
#include "cards.h"
#include <wx/bmpbuttn.h>
#include <random>
#include <chrono>

//(*InternalHeaders(ProjektDialog)
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(ProjektDialog)
const long ProjektDialog::ID_STATICTEXT1 = wxNewId();
const long ProjektDialog::ID_STATICBITMAP1 = wxNewId();
const long ProjektDialog::ID_STATICTEXT2 = wxNewId();
const long ProjektDialog::ID_STATICTEXT3 = wxNewId();
const long ProjektDialog::ID_STATICTEXT6 = wxNewId();
const long ProjektDialog::ID_STATICTEXT7 = wxNewId();
const long ProjektDialog::ID_STATICTEXT4 = wxNewId();
const long ProjektDialog::ID_STATICTEXT5 = wxNewId();
const long ProjektDialog::ID_BITMAPBUTTON1 = wxNewId();
const long ProjektDialog::ID_BITMAPBUTTON2 = wxNewId();
const long ProjektDialog::ID_BITMAPBUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ProjektDialog,wxDialog)
    //(*EventTable(ProjektDialog)
    //*)
END_EVENT_TABLE()

ProjektDialog::ProjektDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ProjektDialog)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxFlexGridSizer* FlexGridSizer1;

    Create(parent, wxID_ANY, _("Gra karciana"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxBORDER_STATIC, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(6, 1, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Nazwa"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
    FlexGridSizer1->Add(StaticBitmap1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Zdrowie:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Pancerz:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Trucizna:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    BoxSizer1->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Informacje o ruchu przeciwnika."), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE|wxALIGN_CENTRE, _T("ID_STATICTEXT7"));
    StaticText7->SetMinSize(wxSize(300,-1));
    FlexGridSizer1->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 15);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Zdrowie:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    BoxSizer2->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Pancerz:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    BoxSizer2->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("Atak.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->SetBitmapDisabled(wxBitmap(wxImage(_T("Atak.png"))));
    BitmapButton1->SetBitmapSelected(wxBitmap(wxImage(_T("Atak.png"))));
    BitmapButton1->SetBitmapFocus(wxBitmap(wxImage(_T("Atak.png"))));
    BoxSizer3->Add(BitmapButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton2 = new wxBitmapButton(this, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("Atak.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BoxSizer3->Add(BitmapButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton3 = new wxBitmapButton(this, ID_BITMAPBUTTON3, wxBitmap(wxImage(_T("Atak.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    BoxSizer3->Add(BitmapButton3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProjektDialog::Gra);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProjektDialog::Gra);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProjektDialog::Gra);
    //*)


pola[0]=BitmapButton1;
pola[1]=BitmapButton2;
pola[2]=BitmapButton3;

Karty[0]=wxBitmap(wxImage("Atak.png"));
Karty[1]=wxBitmap(wxImage("Obrona.png"));
Karty[2]=wxBitmap(wxImage("Leczenie.png"));
Karty[3]=wxBitmap(wxImage("Przetasowanie.png"));
Karty[4]=wxBitmap(wxImage("AtakObrona.png"));
Karty[5]=wxBitmap(wxImage("Trucizna.png"));


Przeciwnicy[0]=wxBitmap(wxImage("krolik2.png"));
Przeciwnicy[1]=wxBitmap(wxImage("waz.png"));
Przeciwnicy[2]=wxBitmap(wxImage("mis.png"));

srand(time(nullptr));
losowyIndexWew = rand() % 3;
OnShowRandomImage();
OnShowRandomImage2();



if(losowyIndexWew==0)
{
    Zycie = 50;
    StaticText2 ->  SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), Zycie));
    StaticText1 ->  SetLabel(wxT("Szalony Król"));
    StaticText3 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzPrzeciwnika));
    StaticText6 ->  SetLabel(wxT("Trucizna: ") + wxString::Format(wxT("%d"), Trucizna));
}
if(losowyIndexWew==1)
{
    Zycie = 75;
    StaticText2 ->  SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), Zycie));
    StaticText1 ->  SetLabel(wxT("Rzeczny Wąż"));
    StaticText3 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzPrzeciwnika));
    StaticText6 ->  SetLabel(wxT("Trucizna: ") + wxString::Format(wxT("%d"), Trucizna));
}
if(losowyIndexWew==2)
{
    Zycie = 100;
    StaticText2 ->  SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), Zycie));
    StaticText1 ->  SetLabel(wxT("Brat Niedzwiedź"));
    StaticText3 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzPrzeciwnika));
    StaticText6 ->  SetLabel(wxT("Trucizna: ") + wxString::Format(wxT("%d"), Trucizna));
}

NaszPancerz = 0;
NaszeZycie = 50;
StaticText4 ->  SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), NaszeZycie));
StaticText5 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), NaszPancerz));

SetIcon(wxICON(aaaa));
SetSizer(FlexGridSizer1);
FlexGridSizer1->Fit(this);
FlexGridSizer1->SetSizeHints(this);
Refresh();
}

ProjektDialog::~ProjektDialog()
{
    //(*Destroy(ProjektDialog)
    //*)
}

void ProjektDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void ProjektDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));

}



void ProjektDialog::OnShowRandomImage() //Wylosowanie przeciwnika
{
    losowyIndexWew;
    StaticBitmap1->SetBitmap(Przeciwnicy[losowyIndexWew]);
}




void ProjektDialog::OnShowRandomImage2() //Ustawienie zdjęć
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937_64 rng(seed);
    std::uniform_int_distribution<int> distribution(0, 5);;
    for(int i=0;i<3;i++)
    {
        int losowyIndex = distribution(rng);
        wxBitmapButton* wybranyPrzycisk;
        switch (i) {
            case 0:
                wybranyPrzycisk = BitmapButton1;
                break;
            case 1:
                wybranyPrzycisk = BitmapButton2;
                break;
            case 2:
                wybranyPrzycisk = BitmapButton3;
                break;
            default:
                break;
        }
        wybranyPrzycisk->SetBitmapLabel(Karty[losowyIndex]);
        wybranyPrzycisk->SetBitmapPressed(Karty[losowyIndex]);
        wybranyPrzycisk->SetBitmapCurrent(Karty[losowyIndex]);
        wybranyPrzycisk->SetBitmapHover(Karty[losowyIndex]);
        wybranyPrzycisk->SetBitmapSelected(Karty[losowyIndex]);
        wybranyPrzycisk->Update();
        this->Refresh();
}

}

void ProjektDialog::DecreaseHealth() //Obrażenia
{
    cards atak(6,0,0,0,0,0,"Atak.png");
    int attackValue=atak.GetAttack();
    int PancerzBlokada = PancerzPrzeciwnika - attackValue;
    if(PancerzBlokada <= 0)
    {
        Zycie += PancerzBlokada;
        PancerzPrzeciwnika = 0;
        StaticText3 -> SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzPrzeciwnika));
        StaticText2 -> SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), Zycie));
        return;
    }
    else
    {
        PancerzPrzeciwnika=PancerzPrzeciwnika-attackValue;
        StaticText3 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzPrzeciwnika));
        return;
    }
}
void ProjektDialog::IncreaseArmor() // Pancerz
{
    cards pancerz(0,5,0,0,0,0,"Obrona.png");
    int armorValue=pancerz.GetArmor();
    NaszPancerz += armorValue;
    StaticText5 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), NaszPancerz));
    return;
}

void ProjektDialog::Healing() //Leczenie
{
    cards leczenie(0,0,3,0,0,0,"Leczenie.png");
    int healValue=leczenie.GetHeal();
    if(NaszeZycie >= 50)
    {
        return;
    }
    NaszeZycie += healValue;
    if(NaszeZycie >= 50)
    {
        NaszeZycie = 50;
        StaticText4 ->  SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), NaszeZycie));
    }
    StaticText4 ->  SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), NaszeZycie));
    return;
}

void ProjektDialog::Shuffle() //Przetasowanie
{
    cards Przetasowanie(0,0,0,1,0,0,"Przetasowanie.png");
    bool shuffleValue=Przetasowanie.GetRefresh();
    if(shuffleValue==1)
    {
        OnShowRandomImage2();
        Tura = 1;
    }
    return;
}

void ProjektDialog::AttackAndArmor()
{
    cards atak_obrona(3,2,0,0,0,0,"AtakObrona.png");
    int attackValue=atak_obrona.GetAttack();
    int armorValue=atak_obrona.GetArmor();
    int PancerzBlokada = PancerzPrzeciwnika - attackValue;
    NaszPancerz += armorValue;
    StaticText5 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), NaszPancerz));
    if(PancerzBlokada <= 0)
    {
        Zycie += PancerzBlokada;
        PancerzPrzeciwnika = 0;
        StaticText3 -> SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzPrzeciwnika));
        StaticText2 -> SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), Zycie));
        return;
    }
    else
    {
        PancerzPrzeciwnika=PancerzPrzeciwnika-attackValue;
        StaticText3 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzPrzeciwnika));
        return;
    }
}

void ProjektDialog::Poison()
{
    cards trucizna(0,0,0,0,0,2,"Trucizna.png");
    Trucizna += trucizna.GetTrucizna();
}

void ProjektDialog::ObrazeniaPoison()
{
    int PancerzBlokada = PancerzPrzeciwnika - Trucizna;
    if(PancerzBlokada <= 0)
    {
        Zycie += PancerzBlokada;
        PancerzPrzeciwnika = 0;
        StaticText3 -> SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzPrzeciwnika));
        StaticText2 -> SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), Zycie));
    }
    else
    {
        PancerzPrzeciwnika=PancerzPrzeciwnika-Trucizna;
        StaticText3 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzPrzeciwnika));
    }
    Trucizna--;
    StaticText6 -> SetLabel(wxT("Trucizna: ") + wxString::Format(wxT("%d"), Trucizna));
}

void ProjektDialog::OnBitmapButtonClick(wxCommandEvent& event) //sprawdza które pole zostało klinkięte
{
    wxBitmapButton* clickedButton = dynamic_cast<wxBitmapButton*>(event.GetEventObject());
    if (clickedButton) // sprawdza które pole zostało klinkięte
    {
        int indeksPrzycisku = -1;
        for (int i = 1; i < 4; i++)
        {
            if (clickedButton == przyciskiKart[i])
            {
                indeksPrzycisku = i;
                break;
            }
        }

        if (indeksPrzycisku != -1) // sprawdza kartę na tym polu
        {
            wxBitmap bitmapOnButton = clickedButton->GetBitmapLabel();
            wxBitmap bitmapAtak = Karty[0];
            wxBitmap bitmapPancerz = Karty[1];
            wxBitmap bitmapLeczenie = Karty[2];
            wxBitmap bitmapTasuj = Karty[3];
            wxBitmap bitmapAtakObrona = Karty[4];
            wxBitmap bitmapTrucizna = Karty[5];

            if (bitmapOnButton.IsSameAs(bitmapAtak))
            {
                DecreaseHealth();
            }

            if (bitmapOnButton.IsSameAs(bitmapPancerz))
            {
                IncreaseArmor();
            }

            if (bitmapOnButton.IsSameAs(bitmapLeczenie))
            {
                Healing();
            }
            if (bitmapOnButton.IsSameAs(bitmapTasuj))
            {
                Shuffle();
            }
            if(bitmapOnButton.IsSameAs(bitmapAtakObrona))
            {
                AttackAndArmor();
            }
            if(bitmapOnButton.IsSameAs(bitmapTrucizna))
            {
                Poison();
            }
        }
    }
}

void ProjektDialog::RuchPrzeciwnika() // ruch przeciwnika
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937_64 rng(seed);
    std::uniform_int_distribution<int> distribution(0, 2);
    int LosowyAtak = distribution(rng);
    if(losowyIndexWew==0) //krolik
    {
        if(LosowyAtak==0)
        {
            NaszeZycie -= 4;
            StaticText4 -> SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), NaszeZycie));
            StaticText7 -> SetLabel(wxT("Przeciwnik zadał ci 4 obrażenia."));
            return;
        }
        if(LosowyAtak==1)
        {
            int PancerzBlokada = NaszPancerz - 10;
            if(PancerzBlokada <= 0)
            {
                NaszeZycie += PancerzBlokada;
                StaticText4 -> SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), NaszeZycie));
                StaticText7 -> SetLabel(wxT("Przeciwnik zadał ci 10 obrażeń."));
                return;
            }
            StaticText5 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzBlokada));
            StaticText7 -> SetLabel(wxT("Przeciwnik zadał ci 10 obrażeń."));
            return;
        }
        PancerzPrzeciwnika += 3;
        StaticText3 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzPrzeciwnika));
        StaticText7 -> SetLabel(wxT("Przeciwnik otrzymał 3 pancerza."));
        return;
    }
    if(losowyIndexWew==1) //waz
    {
        if(LosowyAtak==0)
        {
            int PancerzBlokada = NaszPancerz - 8;
            if(PancerzBlokada <= 0)
            {
                NaszeZycie += PancerzBlokada;
                StaticText4 -> SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), NaszeZycie));
                StaticText7 -> SetLabel(wxT("Przeciwnik zadał ci 5 obrażeń."));
                return;
            }
            StaticText5 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzBlokada));
            StaticText7 -> SetLabel(wxT("Przeciwnik zadał ci 5 obrażeń."));
            return;
        }
        if(LosowyAtak==1)
        {
            NaszPancerz = NaszPancerz/2;
            StaticText5 -> SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), NaszPancerz));
            StaticText7 -> SetLabel(wxT("Przeciwnik zmniejszył twój pancerz o połowę."));
            return;
        }
        PancerzPrzeciwnika += 4;
        StaticText3 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzPrzeciwnika));
        StaticText7 -> SetLabel(wxT("Przeciwnik otrzymał 4 pancerza."));
        return;
    }
    if(losowyIndexWew==2) //mis
    {
        if(LosowyAtak==0)
        {
            if(Zycie >= 100)
            {
                StaticText7 -> SetLabel(wxT("Przeciwnik uleczył się o 4."));
                return;
            }
            Zycie += 4;
            if(Zycie >= 100)
            {
                Zycie = 100;
                StaticText2 -> SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), Zycie));
                StaticText7 -> SetLabel(wxT("Przeciwnik uleczył się o 4."));
                return;
            }
            StaticText2 -> SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), Zycie));
            StaticText7 -> SetLabel(wxT("Przeciwnik uleczył się o 4."));
            return;
        }
        if(LosowyAtak==1)
        {
            int PancerzBlokada = NaszPancerz - 8;
            if(PancerzBlokada <= 0)
            {
                NaszeZycie += PancerzBlokada;
                StaticText4 -> SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), NaszeZycie));
                StaticText7 -> SetLabel(wxT("Przeciwnik zadał ci 8 obrażeń."));
                return;
            }
            StaticText5 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzBlokada));
            StaticText7 -> SetLabel(wxT("Przeciwnik zadał ci 8 obrażeń."));
            return;
        }
        PancerzPrzeciwnika += 5;
        StaticText3 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzPrzeciwnika));
        StaticText7 -> SetLabel(wxT("Przeciwnik otrzymał 5 pancerza."));
        return;
    }
}

void ProjektDialog::InitializeGame()
{
srand(time(nullptr));
losowyIndexWew = rand() % 3;
OnShowRandomImage();
OnShowRandomImage2();

if(losowyIndexWew==0)
{
    Zycie = 50;
    StaticText2 ->  SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), Zycie));
    StaticText1 ->  SetLabel(wxT("Szalony Król"));
    StaticText3 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzPrzeciwnika));
    StaticText6 ->  SetLabel(wxT("Trucizna: ") + wxString::Format(wxT("%d"), Trucizna));
}
if(losowyIndexWew==1)
{
    Zycie = 75;
    StaticText2 ->  SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), Zycie));
    StaticText1 ->  SetLabel(wxT("Rzeczny Wąż"));
    StaticText3 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzPrzeciwnika));
    StaticText6 ->  SetLabel(wxT("Trucizna: ") + wxString::Format(wxT("%d"), Trucizna));
}
if(losowyIndexWew==2)
{
    Zycie = 100;
    StaticText2 ->  SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), Zycie));
    StaticText1 ->  SetLabel(wxT("Brat Niedzwiedź"));
    StaticText3 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), PancerzPrzeciwnika));
    StaticText6 ->  SetLabel(wxT("Trucizna: ") + wxString::Format(wxT("%d"), Trucizna));
}
NaszPancerz = 0;
NaszeZycie = 50;
StaticText4 ->  SetLabel(wxT("Zdrowie: ") + wxString::Format(wxT("%d"), NaszeZycie));
StaticText5 ->  SetLabel(wxT("Pancerz: ") + wxString::Format(wxT("%d"), NaszPancerz));
}

void ProjektDialog::Gra(wxCommandEvent& event) //działanie gry
{
    OnBitmapButtonClick(event);
    OnShowRandomImage2();
    if(Tura==1)
    {
        Tura = 0;
        return;
    }
    RuchPrzeciwnika();
    if(Trucizna > 0)
    {
        ObrazeniaPoison();
    }
    if(NaszeZycie<=0)
    {
        wxMessageBox("Przegrana! Zostales pokonany.", "Koniec gry", wxICON_ERROR | wxOK);
        InitializeGame();
    }
    if(Zycie<=0)
    {
        wxMessageBox("Gratulacje! Przeciwnik pokonany.", "Wygrana", wxICON_INFORMATION | wxOK);
        InitializeGame();
    }
}


