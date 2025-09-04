#include "sinbaram/sinLinkHeader.h"
#include "field.h"
#include "CTeleportWindow.h"
#include "../../../Source EnigmaPT/src/drawsub.h"

char Text[38][32];
const char* InfoMapa[38] = {
    "Level 1 ao 15",
    "Level 1 ao 15",
    "Level 5 ao 15",
    "Level 5 ao 15",
    "Level 1 ao 15",
    "Level 10 ao 20",
    "Level 15 ao 25",
    "Level 25 ao 35",
    "Level 30 ao 40",
    "Level 45 ao 55",
    "Level 55 ao 65",
    "Level 55 ao 65",
    "Level 55 ao 65",
    "Level 55 ao 65",
    "Level 65 ao 75",
    "Level 40 ao 50",
    "Level 50 ao 60",
    "Level 60 ao 70",
    "Level 70 ao 80",
    "Level 75 ao 85",
    "Mapa PvP 70+",
    "Babel - Itens 80A/B",
    "Level 85 ao 95",
    "Cidade Level 90+",
    "Valento - Anel do Valento",
    "Level 90 ao 100",
    "Kelvezu - Colar do Kelvezu",
    "Darkness - Dark Shelton",
    "Mokova - Botas do Mokova",
    "Eventos",
    "Mapa Vazio",
    "Mapa Vazio",
    "Mapa Vazio",
    "Mapa Vazio",
    "Mapa Vazio",
    "Mapa Vazio",
    "Mapa Vazio",
};
const char* FieldNum[38][4] = {
    //Nº Field Level Nome
    { "0", "20", "1", "Estrada dos Ventos" },
    { "1", "19", "1", "Vale Tranquilo" },
    { "2", "17", "1", "Floresta dos Espíritos" },
    { "3", "0", "1", "Mata das Acácias" },
    { "4", "2", "1", "Jardim da Liberdade" },
    { "5", "4", "1", "Refugio dos Ancioes" },
    { "6", "5", "1", "Castelo dos Perdidos" },
    { "7", "7", "25", "Terra Maldita" },
    { "8", "8", "30", "Terra Esquecida" },
    { "9", "10", "40", "Oasis" },
    { "10", "11", "55", "Campo de Batalha" },
    { "11", "12", "55", "Terra Proibida" },
    { "12", "25", "55", "Caverna das Abelhas" },
    { "13", "24", "55", "Caverna dos Cogumelos" },
    { "14", "26", "65", "Santuário Sombrio" },
    { "15", "13", "40", "Calabouço Antigo 1º Andar" },
    { "16", "14", "50", "Calabouço Antigo 2º Andar" },
    { "17", "15", "60", "Calabouço Antigo 3º Andar" },
    { "18", "22", "70", "Templo Maldito 1º Andar" },
    { "19", "23", "75", "Templo Maldito 2º Andar" },
    { "20", "34", "70", "Lago da Ganância" },
    { "21", "27", "80", "Estrada de Ferro do Caos" },
    { "22", "28", "85", "Coração de Perum" },
    { "23", "29", "90", "Eura" },
    { "24", "31", "90", "Vale Gallubia" },
    { "25", "35", "90", "Santuário Congelado" },
    { "26", "36", "90", "Covil de Kelvezu" },
    { "27", "37", "95", "Ilha Perdida" },
    { "28", "38", "100", "Templo Perdido" },
    { "29", "40", "102", "Ilha da Morte" },
    { "30", "40", "102", "DESATIVADO" },
    { "31", "41", "105", "DESATIVADO" },
    { "32", "43", "108", "DESATIVADO" },
    { "33", "44", "110", "DESATIVADO" },
    { "34", "46", "118", "DESATIVADO" },
    { "35", "47", "123", "DESATIVADO" },
    { "36", "48", "130", "DESATIVADO" },
    { "37", "49", "130", "DESATIVADO" }

    /*
    { "30","40", "102", "Torre Sem Fim 1o Andar"},
    { "31","41", "105", "Torre Sem Fim 2º Andar"},
    { "32","43", "108", "Torre Sem Fim 3º Andar"},
    { "33","44", "110", "Mina de Gelo 1º Andar"},
    { "34","46", "118", "Laboratório Secreto"},
    { "35","47", "123", "Arma Secreta"},
    { "36","48", "130", "Abismo do Mar 1º Andar"},
    { "37","49", "130", "Abismo do Mar 2º andar"}*/
};

int mapa, index = 1, click, lvl, imagemapa;
BOOL stop;
int basex = 450;
int basey = 90;
SIZE size4[38] = { };
//extern bool isMousePos(int x, int y, int w, int h);
bool isMousePos(int x, int y, int w, int h)
{
    if (pRealCursorPos.x > x && pRealCursorPos.x < x + w && pRealCursorPos.y > y && pRealCursorPos.y < y + h)
        return true;

    return false;
}
void TCORE::init()
{
    imagens[JANELA] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\window.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[BTNTELEPORT] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\btnteleport.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[BTNTELEPORT_] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\btnteleport_.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[BTNCLOSE] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\close.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[BTNCLOSE_] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\close_.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[EXP] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\exp.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[HUNT] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\hunt.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[GOLD] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\gold.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[TOWN] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\town.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[SHELTONS] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\sheltons.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[PVP] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\pvp.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[HUNTPVP] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\huntpvp.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[12] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\border.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[13] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\page1.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[14] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\page1_.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[15] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\page2.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[16] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\page2_.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[17] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\page3.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[18] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\page3_.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imagens[19] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\expdrop.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[0] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\estrada-dos-ventos.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[1] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\vale-tranquilo.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[2] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\floresta-espirito.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[3] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\mata-acacias.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[4] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\jardim-liberdade.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[5] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\refugio-ancioes.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[6] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\castelo-perdidos.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[7] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\terra-maldita.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[8] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\terra-esquecida.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[9] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\oasis.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[10] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\cba.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[11] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\terra-proibida.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[12] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\bcave.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[13] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\mcave.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[14] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\ds.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[15] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\dun1.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[16] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\dun2.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[17] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\dun3.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[18] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\s1.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[19] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\s2.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    //imgs[20] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\s3.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[20] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\gl.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[21] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\iron1.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[22] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\iron2.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[23] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\eura.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[24] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\ice1.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[25] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\ice2.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[26] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\kcave.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[27] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\lost1.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[28] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\lost2.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[29] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\lost3.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[30] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\et1.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[31] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\et2.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[32] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\et3.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[33] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\mine-ice.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[34] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\slab.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[35] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\AncientW.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[36] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\SeaA.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);
    imgs[37] = CreateTextureMaterial("image\\Sinimage\\shopall\\Core\\Mapas\\Stemple.png", 0, 0, 0, 0, SMMAT_BLEND_ALPHA);

    for (int i = 0; i < 38; i++)
    {
        wsprintf(Text[i], "%d. %s", atoi(FieldNum[i][0]), FieldNum[i][3]);
        GetFontTextExtentPoint(Text[i], lstrlen(Text[i]), &size4[i]);
    }
    //AddChatBuff("szLevelEntrar");
};

void TCORE::DrawImage(int Mat, int x, int y, int w, int h)
{
    HoDrawTexImage(Mat, x, y, w, h, w, h, 255);
}

void TCORE::Draw()
{
    if (Open)
    {
        DWORD CORSELECT = RGB(255, 191, 89);
        DWORD COR = RGB(255, 255, 255);
        DWORD COR1 = RGB(255, 100, 0);
        int cd = (smScreenWidth / 2) - 180;
        stop = TRUE;
        DrawImage(imagens[JANELA], smScreenWidth / 2 - 240, 80, 480, 500);
        DrawImage(imgs[click], smScreenWidth / 2 + 60, 136, 119, 119);

        DrawImage(imagens[12], smScreenWidth / 2 + 50, 130, 145, 130);
        if (index == 1)
        {
            DrawImage(imagens[13], cd + 44, basey + 400, 26, 26);
        }
        else
        {
            DrawImage(imagens[14], cd + 44, basey + 400, 26, 26);
        }
        if (index == 2)
        {
            DrawImage(imagens[15], cd + 74, basey + 400, 26, 26);
        }
        else
        {
            DrawImage(imagens[16], cd + 74, basey + 400, 26, 26);
        }
        if (index == 3)
        {
            DrawImage(imagens[17], cd + 104, basey + 400, 26, 26);
        }
        else
        {
            DrawImage(imagens[18], cd + 104, basey + 400, 26, 26);
        }
        SIZE size4 = { };
        GetFontTextExtentPoint(FieldNum[click][3], lstrlen(FieldNum[click][3]), &size4);
       DrawFontTextNew((smScreenWidth / 2 + 115) - (size4.cx / 2), basey + 170, FieldNum[click][3], CORSELECT, 3);
        size4 = { };
        GetFontTextExtentPoint(InfoMapa[click], lstrlen(InfoMapa[click]), &size4);
      DrawFontTextNew((smScreenWidth / 2 + 115) - (size4.cx / 2), basey + 200, InfoMapa[click], COR, 3);

        char LvlReq[32];
        wsprintf(LvlReq, "Level Requerido %d.", atoi(FieldNum[click][2]));
        size4 = { };
        GetFontTextExtentPoint(LvlReq, lstrlen(LvlReq), &size4);
     DrawFontTextNew((smScreenWidth / 2 + 115) - (size4.cx / 2), basey + 230, LvlReq, COR, 3);

        if (isMousePos(smScreenWidth / 2 + 35, 450, 182, 48))
        {
            DrawImage(imagens[BTNTELEPORT_], smScreenWidth / 2 + 35, 450, 182, 48);
        }
        else
        {
            DrawImage(imagens[BTNTELEPORT], smScreenWidth / 2 + 35, 450, 182, 48);
        }
        if (isMousePos(smScreenWidth / 2 + 210, 82, 26, 26))
        {
            DrawImage(imagens[BTNCLOSE_], smScreenWidth / 2 + 210, 82, 26, 26);
        }
        else
        {
            DrawImage(imagens[BTNCLOSE], smScreenWidth / 2 + 210, 82, 26, 26);
        }

        if (index == 1)
        {
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 40, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 60, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 80, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 100, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 120, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 140, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 160, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 180, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 200, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 220, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 240, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 260, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 280, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 300, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 320, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 340, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 360, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 380, 40, 13);

            size4 = { };
            GetFontTextExtentPoint(Text[0], lstrlen(Text[0]), &size4);
            if (isMousePos(cd, basey + 40, size4.cx + 13, 15))
            {
              DrawFontTextNew(cd, basey + 40, Text[0], COR1, 3);
            }
            else if (click == 0)
            {
              DrawFontTextNew(cd, basey + 40, Text[0], COR1, 3);
            }
            else
            {
              DrawFontTextNew(cd, basey + 40, Text[0], COR, 3);
            }

            //
            size4 = { };
            GetFontTextExtentPoint(Text[1], lstrlen(Text[1]), &size4);
            if (isMousePos(cd, basey + 60, size4.cx + 13, 15))
            {
              DrawFontTextNew(cd, basey + 60, Text[1], COR1, 3);
            }
            else if (click == 1)
            {
              DrawFontTextNew(cd, basey + 60, Text[1], COR1, 3);
            }
            else
            {
              DrawFontTextNew(cd, basey + 60, Text[1], COR, 3);
            }
            //
            size4 = { };
            GetFontTextExtentPoint(Text[2], lstrlen(Text[2]), &size4);
            if (isMousePos(cd, basey + 80, size4.cx + 13, 15))
            {
              DrawFontTextNew(cd, basey + 80, Text[2], COR1, 3);
            }
            else if (click == 2)
            {
              DrawFontTextNew(cd, basey + 80, Text[2], COR1, 3);
            }
            else
            {
              DrawFontTextNew(cd, basey + 80, Text[2], COR, 3);
            }
            //
            size4 = { };
            GetFontTextExtentPoint(Text[3], lstrlen(Text[3]), &size4);
            if (isMousePos(cd, basey + 100, size4.cx + 13, 15))
            {
              DrawFontTextNew(cd, basey + 100, Text[3], COR1, 3);
            }
            else if (click == 3)
            {
               DrawFontTextNew(cd, basey + 100, Text[3], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 100, Text[3], COR, 3);
            }
            //
            size4 = { };
            GetFontTextExtentPoint(Text[4], lstrlen(Text[4]), &size4);
            if (isMousePos(cd, basey + 120, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 120, Text[4], COR1, 3);
            }
            else if (click == 4)
            {
               DrawFontTextNew(cd, basey + 120, Text[4], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 120, Text[4], COR, 3);
            }
            //
            size4 = { };
            GetFontTextExtentPoint(Text[5], lstrlen(Text[5]), &size4);
            if (isMousePos(cd, basey + 140, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 140, Text[5], COR1, 3);
            }
            else if (click == 5)
            {
               DrawFontTextNew(cd, basey + 140, Text[5], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 140, Text[5], COR, 3);
            }
            //
            size4 = { };
            GetFontTextExtentPoint(Text[6], lstrlen(Text[6]), &size4);
            if (isMousePos(cd, basey + 160, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 160, Text[6], COR1, 3);
            }
            else if (click == 6)
            {
               DrawFontTextNew(cd, basey + 160, Text[6], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 160, Text[6], COR, 3);
            }
            size4 = { };
            GetFontTextExtentPoint(Text[7], lstrlen(Text[7]), &size4);
            if (isMousePos(cd, basey + 180, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 180, Text[7], COR1, 3);
            }
            else if (click == 7)
            {
               DrawFontTextNew(cd, basey + 180, Text[7], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 180, Text[7], COR, 3);
            }
            size4 = { };
            GetFontTextExtentPoint(Text[8], lstrlen(Text[8]), &size4);
            if (isMousePos(cd, basey + 200, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 200, Text[8], COR1, 3);
            }
            else if (click == 8)
            {
               DrawFontTextNew(cd, basey + 200, Text[8], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 200, Text[8], COR, 3);
            }
            size4 = { };
            GetFontTextExtentPoint(Text[9], lstrlen(Text[9]), &size4);
            if (isMousePos(cd, basey + 220, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 220, Text[9], COR1, 3);
            }
            else if (click == 9)
            {
               DrawFontTextNew(cd, basey + 220, Text[9], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 220, Text[9], COR, 3);
            }
            size4 = { };
            GetFontTextExtentPoint(Text[10], lstrlen(Text[10]), &size4);
            if (isMousePos(cd, basey + 240, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 240, Text[10], COR1, 3);
            }
            else if (click == 10)
            {
               DrawFontTextNew(cd, basey + 240, Text[10], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 240, Text[10], COR, 3);
            }
            size4 = { };
            GetFontTextExtentPoint(Text[11], lstrlen(Text[11]), &size4);
            if (isMousePos(cd, basey + 260, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 260, Text[11], COR1, 3);
            }
            else if (click == 11)
            {
               DrawFontTextNew(cd, basey + 260, Text[11], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 260, Text[11], COR, 3);
            }
            size4 = { };
            GetFontTextExtentPoint(Text[12], lstrlen(Text[12]), &size4);
            if (isMousePos(cd, basey + 280, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 280, Text[12], COR1, 3);
            }
            else if (click == 12)
            {
               DrawFontTextNew(cd, basey + 280, Text[12], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 280, Text[12], COR, 3);
            }
            size4 = { };
            GetFontTextExtentPoint(Text[13], lstrlen(Text[13]), &size4);
            if (isMousePos(cd, basey + 300, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 300, Text[13], COR1, 3);
            }
            else if (click == 13)
            {
               DrawFontTextNew(cd, basey + 300, Text[13], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 300, Text[13], COR, 3);
            }
            size4 = { };
            GetFontTextExtentPoint(Text[14], lstrlen(Text[14]), &size4);
            if (isMousePos(cd, basey + 320, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 320, Text[14], COR1, 3);
            }
            else if (click == 14)
            {
               DrawFontTextNew(cd, basey + 320, Text[14], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 320, Text[14], COR, 3);
            }
            size4 = { };
            GetFontTextExtentPoint(Text[15], lstrlen(Text[15]), &size4);
            if (isMousePos(cd, basey + 340, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 340, Text[15], COR1, 3);
            }
            else if (click == 15)
            {
               DrawFontTextNew(cd, basey + 340, Text[15], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 340, Text[15], COR, 3);
            }
            size4 = { };
            GetFontTextExtentPoint(Text[16], lstrlen(Text[16]), &size4);
            if (isMousePos(cd, basey + 360, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 360, Text[16], COR1, 3);
            }
            else if (click == 16)
            {
               DrawFontTextNew(cd, basey + 360, Text[16], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 360, Text[16], COR, 3);
            }
            size4 = { };
            GetFontTextExtentPoint(Text[17], lstrlen(Text[17]), &size4);
            if (isMousePos(cd, basey + 380, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 380, Text[17], COR1, 3);
            }
            else if (click == 17)
            {
               DrawFontTextNew(cd, basey + 380, Text[17], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 380, Text[17], COR, 3);
            }
        }
        else if (index == 2)
        {
            //Imagens do Core pvp , sheltons exp dropexp //Caso Queira add mais, So diminui ou aumentar Basey +20 ou -20 Rubinho
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 40, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 60, 40, 13);
            DrawImage(imagens[PVP], smScreenWidth / 2 - 223, basey + 80, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 100, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 120, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 140, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 160, 40, 13);
            DrawImage(imagens[EXP], smScreenWidth / 2 - 223, basey + 180, 40, 13);
            DrawImage(imagens[HUNT], smScreenWidth / 2 - 223, basey + 200, 40, 13);
            DrawImage(imagens[19], smScreenWidth / 2 - 223, basey + 220, 40, 13);
            DrawImage(imagens[19], smScreenWidth / 2 - 223, basey + 240, 40, 13);
            DrawImage(imagens[HUNT], smScreenWidth / 2 - 223, basey + 260, 40, 13);
            //DrawImage(imagens[HUNT], smScreenWidth / 2 - 223, basey + 280, 40, 13);
            //DrawImage(imagens[HUNT], smScreenWidth / 2 - 223, basey + 300, 40, 13);
            //DrawImage(imagens[HUNT], smScreenWidth / 2 - 223, basey + 320, 40, 13);
            //DrawImage(imagens[HUNT], smScreenWidth / 2 - 223, basey + 340, 40, 13);//Mina
            //DrawImage(imagens[HUNT], smScreenWidth / 2 - 223, basey + 360, 40, 13);
            size4 = { };
            GetFontTextExtentPoint(Text[18], lstrlen(Text[18]), &size4);
            if (isMousePos(cd, basey + 40, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 40, Text[18], COR1, 3);
            }
            else if (click == 18)
            {
               DrawFontTextNew(cd, basey + 40, Text[18], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 40, Text[18], COR, 3);
            }

            //
            size4 = { };
            GetFontTextExtentPoint(Text[19], lstrlen(Text[19]), &size4);
            if (isMousePos(cd, basey + 60, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 60, Text[19], COR1, 3);
            }
            else if (click == 19)
            {
               DrawFontTextNew(cd, basey + 60, Text[19], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 60, Text[19], COR, 3);
            }
            //
            size4 = { };
            GetFontTextExtentPoint(Text[20], lstrlen(Text[20]), &size4);
            if (isMousePos(cd, basey + 80, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 80, Text[20], COR1, 3);
            }
            else if (click == 20)
            {
               DrawFontTextNew(cd, basey + 80, Text[20], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 80, Text[20], COR, 3);
            }
            //
            size4 = { };
            GetFontTextExtentPoint(Text[21], lstrlen(Text[21]), &size4);
            if (isMousePos(cd, basey + 100, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 100, Text[21], COR1, 3);
            }
            else if (click == 21)
            {
               DrawFontTextNew(cd, basey + 100, Text[21], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 100, Text[21], COR, 3);
            }
            //
            size4 = { };
            GetFontTextExtentPoint(Text[22], lstrlen(Text[22]), &size4);
            if (isMousePos(cd, basey + 120, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 120, Text[22], COR1, 3);
            }
            else if (click == 22)
            {
               DrawFontTextNew(cd, basey + 120, Text[22], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 120, Text[22], COR, 3);
            }
            //
            size4 = { };
            GetFontTextExtentPoint(Text[23], lstrlen(Text[23]), &size4);
            if (isMousePos(cd, basey + 140, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 140, Text[23], COR1, 3);
            }
            else if (click == 23)
            {
               DrawFontTextNew(cd, basey + 140, Text[23], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 140, Text[23], COR, 3);
            }
            //
            size4 = { };
            GetFontTextExtentPoint(Text[24], lstrlen(Text[24]), &size4);
            if (isMousePos(cd, basey + 160, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 160, Text[24], COR1, 3);
            }
            else if (click == 24)
            {
               DrawFontTextNew(cd, basey + 160, Text[24], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 160, Text[24], COR, 3);
            }
            size4 = { };
            GetFontTextExtentPoint(Text[25], lstrlen(Text[25]), &size4);
            if (isMousePos(cd, basey + 180, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 180, Text[25], COR1, 3);
            }
            else if (click == 25)
            {
               DrawFontTextNew(cd, basey + 180, Text[25], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 180, Text[25], COR, 3);
            }
            size4 = { };
            GetFontTextExtentPoint(Text[26], lstrlen(Text[26]), &size4);
            if (isMousePos(cd, basey + 200, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 200, Text[26], COR1, 3);
            }
            else if (click == 26)
            {
               DrawFontTextNew(cd, basey + 200, Text[26], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 200, Text[26], COR, 3);
            }
            size4 = { };
            GetFontTextExtentPoint(Text[27], lstrlen(Text[27]), &size4);
            if (isMousePos(cd, basey + 220, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 220, Text[27], COR1, 3);
            }
            else if (click == 27)
            {
               DrawFontTextNew(cd, basey + 220, Text[27], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 220, Text[27], COR, 3);
            }
            size4 = { };
            GetFontTextExtentPoint(Text[28], lstrlen(Text[28]), &size4);
            if (isMousePos(cd, basey + 240, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 240, Text[28], COR1, 3);
            }
            else if (click == 28)
            {
               DrawFontTextNew(cd, basey + 240, Text[28], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 240, Text[28], COR, 3);
            }
            size4 = { };
            GetFontTextExtentPoint(Text[29], lstrlen(Text[29]), &size4);
            if (isMousePos(cd, basey + 260, size4.cx + 13, 15))
            {
               DrawFontTextNew(cd, basey + 260, Text[29], COR1, 3);
            }
            else if (click == 29)
            {
               DrawFontTextNew(cd, basey + 260, Text[29], COR1, 3);
            }
            else
            {
               DrawFontTextNew(cd, basey + 260, Text[29], COR, 3);
            }
            //size4 = {};
            //GetFontTextExtentPoint(Text[30], lstrlen(Text[30]), &size4);
            //if (isMousePos(cd, basey + 280, size4.cx + 13, 15)) {
            //DrawFontTextNew(cd, basey + 280, Text[30], COR1, 3);
            //}
            //else if (click == 30) {
            //DrawFontTextNew(cd, basey + 280, Text[30], COR1, 3);
            //}
            //else {
            //DrawFontTextNew(cd, basey + 280, Text[30], COR, 3);
            //}
            //size4 = {};
            //GetFontTextExtentPoint(Text[31], lstrlen(Text[31]), &size4);
            //if (isMousePos(cd, basey + 300, size4.cx + 13, 15)) {
            //DrawFontTextNew(cd, basey + 300, Text[31], COR1, 3);
            //}
            //else if (click == 31) {
            //DrawFontTextNew(cd, basey + 300, Text[31], COR1, 3);
            //
            //}
            //else {
            //DrawFontTextNew(cd, basey + 300, Text[31], COR, 3);
            //}
            //size4 = {};
            //GetFontTextExtentPoint(Text[32], lstrlen(Text[32]), &size4);
            //if (isMousePos(cd, basey + 320, size4.cx + 13, 15)) {
            //DrawFontTextNew(cd, basey + 320, Text[32], COR1, 3);
            //}
            //else if (click == 32) {
            //DrawFontTextNew(cd, basey + 320, Text[32], COR1, 3);
            //}
            //else {
            //DrawFontTextNew(cd, basey + 320, Text[32], COR, 3);
            //}
            //size4 = {};
            //GetFontTextExtentPoint(Text[33], lstrlen(Text[33]), &size4);
            //if (isMousePos(cd, basey + 340, size4.cx + 13, 15)) {
            //DrawFontTextNew(cd, basey + 340, Text[33], COR1, 3);
            //}
            //else if (click == 33) {
            //DrawFontTextNew(cd, basey + 340, Text[33], COR1, 3);
            //}
            //else {
            //DrawFontTextNew(cd, basey + 340, Text[33], COR, 3);
            //}
            //size4 = {};
            //GetFontTextExtentPoint(Text[34], lstrlen(Text[34]), &size4);
            //if (isMousePos(cd, basey + 360, size4.cx + 13, 15)) {
            //DrawFontTextNew(cd, basey + 360, Text[34], COR1, 3);
            //}
            //else if (click == 34) {
            //DrawFontTextNew(cd, basey + 360, Text[34], COR1, 3);
            //}
            //else {
            //DrawFontTextNew(cd, basey + 360, Text[34], COR, 3);
            //}
            //size4 = {};
            //GetFontTextExtentPoint(Text[35], lstrlen(Text[35]), &size4);
            //if (isMousePos(cd, basey + 380, size4.cx + 13, 15)) {
            //DrawFontTextNew(cd, basey + 380, Text[35], COR1, 3);
            //}
            //else if (click == 35) {
            //DrawFontTextNew(cd, basey + 380, Text[35], COR1, 3);
            //}
            //else {
            //DrawFontTextNew(cd, basey + 380, Text[35], COR, 3);
            //}
        }
        else if (index == 3)
        {
            //size4 = {};
            //GetFontTextExtentPoint(Text[36], lstrlen(Text[36]), &size4);
            //if (isMousePos(cd, basey + 40, size4.cx + 13, 15)) {
            //
            //DrawFontTextNew(cd, basey + 40, Text[36], COR1, 3);
            //}
            //else if (click == 36) {
            //DrawFontTextNew(cd, basey + 40, Text[36], COR1, 3);
            //
            //
            //}
            //else {
            //DrawFontTextNew(cd, basey + 40, Text[36], COR, 3);
            //}
            //
            ////
            //size4 = {};
            //GetFontTextExtentPoint(Text[37], lstrlen(Text[37]), &size4);
            //if (isMousePos(cd, basey + 60, size4.cx + 13, 15)) {
            //DrawFontTextNew(cd, basey + 60, Text[37], COR1, 3);
            //}
            //else if (click == 37) {
            //DrawFontTextNew(cd, basey + 60, Text[37], COR1, 3);
            //}
            //else {
            //DrawFontTextNew(cd, basey + 60, Text[37], COR, 3);}
        }
    }
}

bool TCORE::MouseIn()
{
    int cd = (smScreenWidth / 2) - 180;
    DWORD COR = RGB(255, 100, 0);
    if (Open)
    {
        if (isMousePos((smScreenWidth / 2) - 180 + 44, basey + 400, 26, 26))
        {
            index = 1;
        }

        if (isMousePos((smScreenWidth / 2) - 180 + 74, basey + 400, 26, 26))
        {
            index = 2;
        }
        if (isMousePos((smScreenWidth / 2) - 180 + 104, basey + 400, 26, 26))
        {
            index = 3;
        }
        if (isMousePos(smScreenWidth / 2 + 210, 82, 26, 26))
        {
            tcoreClose();
            stop = FALSE;
        }
        if (index == 1)
        {
            if (isMousePos(cd, basey + 40, 120, 15))
            {
                mapa = atoi(FieldNum[0][1]);
                click = atoi(FieldNum[0][0]);
                lvl = atoi(FieldNum[0][2]);
            }
            if (isMousePos(cd, basey + 60, 120, 15))
            {
                mapa = atoi(FieldNum[1][1]);
                click = atoi(FieldNum[1][0]);
                lvl = atoi(FieldNum[1][2]);
            }
            if (isMousePos(cd, basey + 80, size4[2].cx + 13, 15))
            {
                mapa = atoi(FieldNum[2][1]);
                click = atoi(FieldNum[2][0]);
                lvl = atoi(FieldNum[2][2]);
            }
            if (isMousePos(cd, basey + 100, size4[3].cx + 13, 15))
            {
                mapa = atoi(FieldNum[3][1]);
                click = atoi(FieldNum[3][0]);
                lvl = atoi(FieldNum[3][2]);
            }
            if (isMousePos(cd, basey + 120, size4[4].cx + 13, 15))
            {
                mapa = atoi(FieldNum[4][1]);
                click = atoi(FieldNum[4][0]);
                lvl = atoi(FieldNum[4][2]);
            }
            if (isMousePos(cd, basey + 140, size4[5].cx + 13, 15))
            {
                mapa = atoi(FieldNum[5][1]);
                click = atoi(FieldNum[5][0]);
                lvl = atoi(FieldNum[5][2]);
            }
            if (isMousePos(cd, basey + 160, size4[6].cx + 13, 15))
            {
                mapa = atoi(FieldNum[6][1]);
                click = atoi(FieldNum[6][0]);
                lvl = atoi(FieldNum[6][2]);
            }
            if (isMousePos(cd, basey + 180, size4[7].cx + 13, 15))
            {
                mapa = atoi(FieldNum[7][1]);
                click = atoi(FieldNum[7][0]);
                lvl = atoi(FieldNum[7][2]);
            }
            if (isMousePos(cd, basey + 200, size4[8].cx + 13, 15))
            {
                mapa = atoi(FieldNum[8][1]);
                click = atoi(FieldNum[8][0]);
                lvl = atoi(FieldNum[8][2]);
            }
            if (isMousePos(cd, basey + 220, size4[9].cx + 13, 15))
            {
                mapa = atoi(FieldNum[9][1]);
                click = atoi(FieldNum[9][0]);
                lvl = atoi(FieldNum[9][2]);
            }
            if (isMousePos(cd, basey + 240, size4[10].cx + 13, 15))
            {
                mapa = atoi(FieldNum[10][1]);
                click = atoi(FieldNum[10][0]);
                lvl = atoi(FieldNum[10][2]);
            }
            if (isMousePos(cd, basey + 260, size4[11].cx + 13, 15))
            {
                mapa = atoi(FieldNum[11][1]);
                click = atoi(FieldNum[11][0]);
                lvl = atoi(FieldNum[11][2]);
            }
            if (isMousePos(cd, basey + 280, size4[12].cx + 13, 15))
            {
                mapa = atoi(FieldNum[12][1]);
                click = atoi(FieldNum[12][0]);
                lvl = atoi(FieldNum[12][2]);
            }
            if (isMousePos(cd, basey + 300, size4[13].cx + 13, 15))
            {
                mapa = atoi(FieldNum[13][1]);
                click = atoi(FieldNum[13][0]);
                lvl = atoi(FieldNum[13][2]);
            }
            if (isMousePos(cd, basey + 320, size4[14].cx + 13, 15))
            {
                mapa = atoi(FieldNum[14][1]);
                click = atoi(FieldNum[14][0]);
                lvl = atoi(FieldNum[14][2]);
            }
            if (isMousePos(cd, basey + 340, size4[15].cx + 13, 15))
            {
                mapa = atoi(FieldNum[15][1]);
                click = atoi(FieldNum[15][0]);
                lvl = atoi(FieldNum[15][2]);
            }
            if (isMousePos(cd, basey + 360, size4[16].cx + 13, 15))
            {
                mapa = atoi(FieldNum[16][1]);
                click = atoi(FieldNum[16][0]);
                lvl = atoi(FieldNum[16][2]);
            }
            if (isMousePos(cd, basey + 380, size4[17].cx + 13, 15))
            {
                mapa = atoi(FieldNum[17][1]);
                click = atoi(FieldNum[17][0]);
                lvl = atoi(FieldNum[17][2]);
            }
        }
        else if (index == 2)
        {
            ////////////
            if (isMousePos(cd, basey + 40, size4[18].cx + 13, 15))
            {
                mapa = atoi(FieldNum[18][1]);
                click = atoi(FieldNum[18][0]);
                lvl = atoi(FieldNum[18][2]);
            }
            if (isMousePos(cd, basey + 60, size4[19].cx + 13, 15))
            {
                mapa = atoi(FieldNum[19][1]);
                click = atoi(FieldNum[19][0]);
                lvl = atoi(FieldNum[19][2]);
            }
            if (isMousePos(cd, basey + 80, size4[20].cx + 13, 15))
            {
                mapa = atoi(FieldNum[20][1]);
                click = atoi(FieldNum[20][0]);
                lvl = atoi(FieldNum[20][2]);
            }
            if (isMousePos(cd, basey + 100, size4[21].cx + 13, 15))
            {
                mapa = atoi(FieldNum[21][1]);
                click = atoi(FieldNum[21][0]);
                lvl = atoi(FieldNum[21][2]);
            }
            if (isMousePos(cd, basey + 120, size4[22].cx + 13, 15))
            {
                mapa = atoi(FieldNum[22][1]);
                click = atoi(FieldNum[22][0]);
                lvl = atoi(FieldNum[22][2]);
            }
            if (isMousePos(cd, basey + 140, size4[23].cx + 13, 15))
            {
                mapa = atoi(FieldNum[23][1]);
                click = atoi(FieldNum[23][0]);
                lvl = atoi(FieldNum[23][2]);
            }
            if (isMousePos(cd, basey + 160, size4[24].cx + 13, 15))
            {
                mapa = atoi(FieldNum[24][1]);
                click = atoi(FieldNum[24][0]);
                lvl = atoi(FieldNum[24][2]);
            }
            if (isMousePos(cd, basey + 180, size4[25].cx + 13, 15))
            {
                mapa = atoi(FieldNum[25][1]);
                click = atoi(FieldNum[25][0]);
                lvl = atoi(FieldNum[25][2]);
            }
            if (isMousePos(cd, basey + 200, size4[26].cx + 13, 15))
            {
                mapa = atoi(FieldNum[26][1]);
                click = atoi(FieldNum[26][0]);
                lvl = atoi(FieldNum[26][2]);
            }
            if (isMousePos(cd, basey + 220, size4[27].cx + 13, 15))
            {
                mapa = atoi(FieldNum[27][1]);
                click = atoi(FieldNum[27][0]);
                lvl = atoi(FieldNum[27][2]);
            }
            if (isMousePos(cd, basey + 240, size4[28].cx + 13, 15))
            {
                mapa = atoi(FieldNum[28][1]);
                click = atoi(FieldNum[28][0]);
                lvl = atoi(FieldNum[28][2]);
            }
            if (isMousePos(cd, basey + 260, size4[29].cx + 13, 15))
            {
                mapa = atoi(FieldNum[29][1]);
                click = atoi(FieldNum[29][0]);
                lvl = atoi(FieldNum[29][2]);
            }
            if (isMousePos(cd, basey + 280, size4[30].cx + 13, 15)) { //ETI1
            mapa = atoi(FieldNum[30][1]);
            click = atoi(FieldNum[30][0]);
            lvl = atoi(FieldNum[30][2]);
            }
            if (isMousePos(cd, basey + 300, size4[31].cx + 13, 15)) { //ET2
            mapa = atoi(FieldNum[31][1]);
            click = atoi(FieldNum[31][0]);
            lvl = atoi(FieldNum[31][2]);
            }
            /* if (isMousePos(cd, basey + 320, size4[32].cx + 13, 15)) {
            mapa = atoi(FieldNum[32][1]);
            click = atoi(FieldNum[32][0]);
            lvl = atoi(FieldNum[32][2]);
            }
            if (isMousePos(cd, basey + 340, size4[33].cx + 13, 15)) {
            mapa = atoi(FieldNum[33][1]);
            click = atoi(FieldNum[33][0]);
            lvl = atoi(FieldNum[33][2]);
            }
            if (isMousePos(cd, basey + 360, size4[34].cx + 13, 15)) {
            mapa = atoi(FieldNum[34][1]);
            click = atoi(FieldNum[34][0]);
            lvl = atoi(FieldNum[34][2]);
            }
            if (isMousePos(cd, basey + 380, size4[35].cx + 13, 15)) {
            mapa = atoi(FieldNum[35][1]);
            click = atoi(FieldNum[35][0]);
            lvl = atoi(FieldNum[35][2]);
            }*/
        }

        //////////////////
        /*else if (index == 3) {
        if (isMousePos(cd, basey + 40, size4[36].cx + 13, 15)) {
        mapa = atoi(FieldNum[36][1]);
        click = atoi(FieldNum[36][0]);
        lvl = atoi(FieldNum[36][2]);
        }
        if (isMousePos(cd, basey + 60, size4[37].cx + 13, 15)) {
        mapa = atoi(FieldNum[37][1]);
        click = atoi(FieldNum[37][0]);
        lvl = atoi(FieldNum[37][2]);
        }
        }*/

        if (isMousePos(smScreenWidth / 2 + 35, 450, 182, 48))
        {
            if (lpCurPlayer->smCharInfo.Level < lvl)
            {
                cMessageBox.ShowMessage(91);
                return FALSE;
            }
            else if (StageField[lpCurPlayer->OnStageField]->FieldCode == 16 || StageField[lpCurPlayer->OnStageField]->FieldCode == 30)
            {
                cMessageBox.ShowMessage(92);
                return FALSE;
            }
            WarpField2(mapa);
            tcoreClose();
            stop = FALSE;
            //sinThrowItemToFeild(&cInvenTory.InvenItem[chaPremiumitem.TelePortCore.ItemIndex]);
            cInvenTory.InvenItem[chaPremiumitem.TelePortCore.ItemIndex].Flag = 0;
            cInvenTory.CheckWeight();
            cInvenTory.ReFormInvenItem();
        }
    }
    return TRUE;
}