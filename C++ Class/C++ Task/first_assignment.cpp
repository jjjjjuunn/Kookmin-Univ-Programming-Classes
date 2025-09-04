#include <iostream>
using namespace std;

class Camera
{
public:
    int Cost = 100;
    int MinNumber = 6;
    int MaxNumber = 12;
    string name = "Kookmin_Camera";
    void CameraCostChange(Camera *c, int N);
};

void Camera :: CameraCostChange(Camera *c, int N){
    cout << "CameraCostChange function is called. CameraCost = N*CameraCost" << endl;
    this -> Cost = (*c).Cost * N ;
    cout << "CameraCost is " << Cost << " Now"<< endl;
}

class Radar
{
public:
    int Cost = 500;
    int MinNumber = 4;
    int MaxNumber = 8;
    string name = "Kookmin_Radar";
    void RadarCostChange(Radar *R, int N);
};

void Radar :: RadarCostChange(Radar *c, int N){
    cout << "RadarCostChange function is called. RadarCost = N*RadarCost" << endl;
    this -> Cost = (*c).Cost * N ;
    cout << "RadarCost is " << Cost << " Now"<< endl;
}

class Lidar
{
public:
    int Cost = 2000;
    int MinNumber = 2;
    int MaxNumber = 6;
    string name = "Kookmin_Lidar";
    void LidarCostChange(Lidar &L,int N);
};

void Lidar::LidarCostChange(Lidar &L,int N){
    cout << "LidarCostChange function is called. LidarCost = N*LidarCost" << endl;
    this -> Cost = L.Cost * N ;
    cout << "LidarCost is " << Cost << " Now"<< endl;
}

int main(void)
{
    Camera *camera = new Camera;
    Radar *radar = new Radar;
    Lidar *lidar = new Lidar;
    int budget;

    cout << "===== Camera, Radar, Lidar information =====" << endl;
    cout << "Camera's name =" <<(*camera).name<< ", Minumum Number="<<(*camera).MinNumber <<", Maximum Number="<<(*camera).MaxNumber<<endl;
    cout << "Radar's name =" <<(*radar).name<< ", Minumum Number="<<(*radar).MinNumber <<", Maximum Number="<<(*radar).MaxNumber<<endl;
    cout << "Lidar's name =" <<(*lidar).name<< ", Minumum Number="<<(*lidar).MinNumber <<", Maximum Number="<<(*lidar).MaxNumber<<endl;
    
    bool loop = true;
    while(loop)
    {
        cout << "Please set the budget: ";
        cin >> budget;
        if (budget >= ((*camera).Cost * (*camera).MinNumber + 
           (*radar).Cost * (*radar).MinNumber + 
           (*lidar).Cost * (*lidar).MinNumber) &&
            budget <= ((*camera).Cost * (*camera).MaxNumber + 
            (*radar).Cost * (*radar).MaxNumber + 
            (*lidar).Cost * (*lidar).MaxNumber))
            {
                loop = false;
            }

        else {
            cout<<"Budget has an incorrect value." << endl;
        }
    }
    cout << "Select the system mode( 0=Total cost, 1=Number of possible combination, 2=Cost change ): ";
    
    int mode;
    cin >> mode;

    if (mode == 0){
        int num_camera;
        int num_radar;
        int num_lidar;
        loop=true;
        while(loop)
        {
        cout << "Decide the number of Camera, Radar, Lidar:";
        cin >> num_camera >> num_radar >> num_lidar ;
        if(num_camera < (*camera).MinNumber || num_camera > (*camera).MaxNumber ||
           num_radar < (*radar).MinNumber || num_radar > (*radar).MaxNumber || 
           num_lidar < (*lidar).MinNumber || num_lidar > (*lidar).MaxNumber )
           {
            cout << "Number of Camera, Radar, Lidar have incorrect values." << endl;
           }
        else loop = false;
        }
        cout << "Total cost for Camera, Radar, Lidar is "<< num_camera * (*camera).Cost + num_radar * (*radar).Cost + num_lidar * (*lidar).Cost << endl;
    }
    else if(mode == 1)
    {
        int count = 0;
        for(int i=6; i<=12 ; i++)
            for(int j=4 ; j<=8 ; j++)
                for(int k=2 ; k<=6 ; k++)
                {
                    if(((*camera).Cost*i + (*radar).Cost*j + (*lidar).Cost*k) <= budget) count++;
                }
        cout << "Number of possible combination is " << count << endl;
    }

    else if(mode == 2)
    {
        Lidar &lidar_refc = *lidar;

        (*camera).CameraCostChange(camera,2);
        (*radar).RadarCostChange(radar,4);
        (*lidar).LidarCostChange(lidar_refc,6);
    }

    else
    {
        cout << "Invalid Mode selected. Program will terminate." << endl;
        exit(1);
    }

    delete camera;
    delete radar;
    delete lidar;
    
    return 0;
}