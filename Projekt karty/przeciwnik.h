
using namespace std;

class przeciwnik
{
public:
    przeciwnik(int Zdrowie,int Atak, int Tarcza);
    int attack();
    int defense();

private:
  int zdrowie;
  int pancerz;
  int atak;
  int tarcza;
};
