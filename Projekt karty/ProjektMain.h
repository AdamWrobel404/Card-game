/***************************************************************
 * Name:      ProjektMain.h
 * Purpose:   Defines Application Frame
 * Author:    Mateusz Wrzosek ()
 * Created:   2023-12-13
 * Copyright: Mateusz Wrzosek ()
 * License:
 **************************************************************/

#ifndef PROJEKTMAIN_H
#define PROJEKTMAIN_H


//(*Headers(ProjektDialog)
#include <wx/bmpbuttn.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
//*)

class ProjektDialog: public wxDialog
{
    public:

        ProjektDialog(wxWindow* parent,wxWindowID id = -1   );
        virtual ~ProjektDialog();
        int GetAtakValue();

    private:

        //(*Handlers(ProjektDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnBitmapButton1Click(wxCommandEvent& event);
        void Gra(wxCommandEvent& event);
        //*)

        //(*Identifiers(ProjektDialog)
        static const long ID_STATICTEXT1;
        static const long ID_STATICBITMAP1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON2;
        static const long ID_BITMAPBUTTON3;
        //*)

        //(*Declarations(ProjektDialog)
        wxBitmapButton* BitmapButton1;
        wxBitmapButton* BitmapButton2;
        wxBitmapButton* BitmapButton3;
        wxStaticBitmap* StaticBitmap1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        //*)

        DECLARE_EVENT_TABLE()

        void OnShowRandomImage();
        void OnShowRandomImage2();
        void OnBitmapButtonClick(wxCommandEvent& event);
        void DecreaseHealth();
        void IncreaseArmor();
        void Healing();
        void Shuffle();
        void RuchPrzeciwnika();
        void AttackAndArmor();
        void Poison();
        void ObrazeniaPoison();

        wxBitmapButton* pola[3];
        wxBitmap Karty[6];
        wxBitmap Przeciwnicy[3];
        wxBitmapButton* przyciskiKart[3];
        int Zycie;
        int PancerzPrzeciwnika = 0;
        int NaszPancerz = 0;
        int NaszeZycie = 30;
        int losowyIndexWew;
        int PancerzPrzeciwnik = 0;
        int Tura=0;
        int Trucizna = 0;


        void InitializeGame();
};

#endif // PROJEKTMAIN_H
