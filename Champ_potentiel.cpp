#include "Champ_potentiel.h"
#include "Vecteur2D.h"
#include "Montagne.h"
#include <vector>
using namespace std;

Vecteur2D Potentiel::get_potentiel() const {
    return potentiel;
}

Vecteur2D Potentiel::get_laplacien() const {
    return laplacien;
}

void Potentiel::set_potentiel(double x, double y) {
    potentiel.set_coord(x,y);
}

void Potentiel::set_laplacien(double x, double y) {
    laplacien.set_coord(x,y);
}

void ChampPotentiels::set_xyz() {
    for (int i = 0; i < Nx; ++i) {
        set_value_x((i+1)*lambda,i);
    }
    for (int j = 0; j < Ny; ++j) {
        set_value_y(((j+1)-(Ny-1)/2)*lambda,j);
    }
    for (int k = 0; k < Nz; ++k) {
        set_value_z((k+1)*lambda,k);
    }
}

void ChampPotentiels::initialise(double v_inf, const Montagne &everest) {
    for (int i = 0; i < Nx ; ++i) {
        for (int j = 0; j < Ny; ++j) {
            for (int k = 0; k < Nz; ++k) {
                collection3D[i][j][k].set_laplacien(0,0);
                collection3D[i][j][k].set_potentiel((v_inf/2)*i,X[j]);
            }
        }
    }

    for (int m = 0; m < 5; ++m) {
        for (int n = 0; n < 5; ++n) {
            for (int o= 0; o < 5; ++o) {
                cout<<collection3D[m][n][o].get_potentiel()<<endl;
            }

        }

    }
}

void ChampPotentiels:: set_value_x(double x,int i){
    X.push_back(x);
}

void ChampPotentiels:: set_value_y(double y,int j){
    Y.push_back(y);
}

void ChampPotentiels:: set_value_z(double z,int k){
    Z.push_back(z);
}