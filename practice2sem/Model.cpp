#include "Model.h"

std::vector<double> Model::getData() {
    return data;
}

double Model::getData(int i) {
    return data[i];
}

void Model::setData(int i, double data) {
    this->data[i] = data;
}


void Model::calculateAcceleration(std::vector<double> &data, std::vector<double> &datanew, double k) {
    data.reserve(6);
    data[0] = datanew[3];
    data[1] = datanew[4];
    data[2] = datanew[5];
    data[3] = 0;
    data[4] = 0;
    data[5] = -G * M / std::pow(R + datanew[2], 2);;
}

void SimpleModel::calculateAcceleration(std::vector<double> &data, std::vector<double> &datanew, double k) {
    double modV = sqrt(datanew[3] * datanew[3] + datanew[4] * datanew[4] + datanew[5] * datanew[5]);

    Model::calculateAcceleration(data, datanew, k);


    data[3] += -k * modV * datanew[3];
    data[4] += -k * modV * datanew[4];
    data[5] += -k * modV * datanew[5];

}

double Counter::calculateCoordinates(double s0, double v, double dt, double a) {
    return (s0 + v * dt + ((a * pow(dt, 2)) / 2));
}

double Counter::calculateSpeed(double v0, double a, double t) { return v0 + a * t; }

void Counter::count(std::string filename, double t, double dt, std::vector<double> data, Model *model, double k) {
    std::ofstream outfile(filename);
    data.reserve(6);
    outfile << "X,Y,Z,Vx,Vy,Vz,Time" << std::endl;
    //std::cout << "X,Y,Z,Vx,Vy,Vz,Time" << std::endl;


    while (data[2] > 0) {

        t += dt;


        model->calculateAcceleration(model->data, data, k);

        for (int j = 0; j < 6; ++j) {
            data[j] += model->data[j]*dt;
            // std::cout << data[j] << ",";
            outfile << data[j] << ",";

        }
        //std::cout << t << std::endl;
        outfile << t << std::endl;

    }
    outfile.close();


}

