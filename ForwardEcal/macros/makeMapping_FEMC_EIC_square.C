#include <iostream>
#include <fstream>
#include <TMath.h>

using namespace std;

void makeMapping_FEMC_EIC_square( TString setup="FwdSquare_ROS")
{
  bool squarecutout = false;
  /* Global detector position / transformation */
  double femc_x0 = 0.0; // cm,
  double femc_y0 = 0.0; // cm,
  double femc_z0 = 0.0; // cm,

  double femc_rot_x0 = 0.0;
  double femc_rot_y0 = 0.0;
  double femc_rot_z0 = 0.0;

  /* Detector envelope size (cone shape) */
  double femc_rmin1 = 0; // cm
  double femc_rmax1 = 0; // cm
  double femc_rmin2 = 0; // cm
  double femc_rmax2 = 0; // cm
  double femc_dz = 0; // cm

  /* Tower parameters */
  double tower_dx = 0.0; // cm
  double tower_dy = 0.0; // cm
  double tower_dz = 0.0; // cm
  double tower_ROS = 1.0; // cm

  double offset_rmin_x = 0.0; // cm
  double offset_rmin_y = 0.0; // cm

  cout << "Setup selected: " << setup << endl;

  if ( setup == "PHENIXEMCal" )
    {
      /* Global detector position / transformation */
      femc_x0 =  0.0; // cm,
      femc_y0 =  0.0; // cm,
      femc_z0 = 310.0; // cm,

      femc_rot_x0 =  0.0;
      femc_rot_y0 =  0.0;
      femc_rot_z0 =  0.0;

      /* Detector envelope size (cone shape) */
      femc_rmin1 = 11.0; // cm - accomodate Mar 2020 EIC beam pipe // was 20cm
      femc_rmax1 = 182.655; // cm
      femc_rmin2 = 12.0; // cm - accomodate Mar 2020 EIC beam pipe // was 20cm
      femc_rmax2 = 182.655; // cm
      femc_dz = 36.5; // cm (FULL SIZE)

      /* Tower parameters */
      // From PHENIX EMCal JGL 12/27/2015
      tower_dx = 5.535; // cm
      tower_dy = 5.535; // cm
      tower_dz = 36.3; // cm (FULL SIZE)
    }
  else if ( setup == "PHENIXEMCal_2x" )
    {
      /* Global detector position / transformation */
      femc_x0 =  0.0; // cm,
      femc_y0 =  0.0; // cm,
      femc_z0 = 310.0; // cm,

      femc_rot_x0 =  0.0;
      femc_rot_y0 =  0.0;
      femc_rot_z0 =  0.0;

      /* Detector envelope size (cone shape) */
      femc_rmin1 = 16.0; // cm - accomodate Mar 2020 EIC beam pipe // was 20cm
      femc_rmax1 = 182.655; // cm
      femc_rmin2 = 16.0; // cm - accomodate Mar 2020 EIC beam pipe // was 20cm
      femc_rmax2 = 182.655; // cm
      femc_dz = 36.5; // cm (FULL SIZE)

      /* Tower parameters */
      // From PHENIX EMCal JGL 12/27/2015
      tower_dx = 5.535/2; // cm
      tower_dy = 5.535/2; // cm
      tower_dz = 36.3; // cm (FULL SIZE)
    }
  else if ( setup == "PHENIXEMCal" )
    {
      /* Global detector position / transformation */
      femc_x0 =  0.0; // cm,
      femc_y0 =  0.0; // cm,
      femc_z0 = 310.0; // cm,

      femc_rot_x0 =  0.0;
      femc_rot_y0 =  0.0;
      femc_rot_z0 =  0.0;

      /* Detector envelope size (cone shape) */
      femc_rmin1 = 11.0; // cm - accomodate Mar 2020 EIC beam pipe
      femc_rmax1 = 182.655; // cm
      femc_rmin2 = 12.0; // cm - accomodate Mar 2020 EIC beam pipe
      femc_rmax2 = 182.655; // cm
      femc_dz = 36.5; // cm (FULL SIZE)

      /* Tower parameters */
      // From PHENIX EMCal JGL 12/27/2015
      tower_dx = 5.535; // cm
      tower_dy = 5.535; // cm
      tower_dz = 36.3; // cm (FULL SIZE)
    }
  else if ( setup == "asymmetric" )
    {
      /* Global detector position / transformation */
      femc_x0 =  0.0; // cm,
      femc_y0 =  0.0; // cm,
      femc_z0 = 310.0; // cm,

      femc_rot_x0 =  0.0;
      femc_rot_y0 =  0.0;
      femc_rot_z0 =  0.0;

      /* Detector envelope size (cone shape) */
      femc_rmin1 = 20.0; // cm - accomodate Mar 2020 EIC beam pipe
      femc_rmax1 = 182.655; // cm
      femc_rmin2 = 20.0; // cm - accomodate Mar 2020 EIC beam pipe
      femc_rmax2 = 182.655; // cm
      femc_dz = 36.5; // cm (FULL SIZE)

      /* Tower parameters */
      // From PHENIX EMCal JGL 12/27/2015
      tower_dx = 5.535; // cm
      tower_dy = 5.535; // cm
      tower_dz = 36.3; // cm (FULL SIZE)

      offset_rmin_x = 10.0; // cm
      offset_rmin_y = 0.0; // cm
    }
  else if ( setup == "wDR" )
    {
      /* Global detector position / transformation */
      femc_x0 =  0.0; // cm,
      femc_y0 =  0.0; // cm,
      femc_z0 = 310.0; // cm,

      femc_rot_x0 =  0.0;
      femc_rot_y0 =  0.0;
      femc_rot_z0 =  0.0;

      /* Detector envelope size (cone shape) */
      femc_rmin1 = 52.0; // cm - accomodate Mar 2020 EIC beam pipe
      femc_rmax1 = 182.655; // cm
      femc_rmin2 = 52.0; // cm - accomodate Mar 2020 EIC beam pipe
      femc_rmax2 = 182.655; // cm
      femc_dz = 36.5; // cm (FULL SIZE)

      /* Tower parameters */
      // From PHENIX EMCal JGL 12/27/2015
      tower_dx = 5.535; // cm
      tower_dy = 5.535; // cm
      tower_dz = 36.3; // cm (FULL SIZE)
    }
  else if ( setup == "FwdSquare" )
    {
      squarecutout = true;
      /* Global detector position / transformation */
      femc_x0 =  0.0; // cm,
      femc_y0 =  0.0; // cm,
      femc_z0 = 310.0; // cm,

      femc_rot_x0 =  0.0;
      femc_rot_y0 =  0.0;
      femc_rot_z0 =  0.0;

      /* Detector envelope size (cone shape) */
      femc_rmin1 = 50.0; // cm - accomodate Mar 2020 EIC beam pipe
      femc_rmax1 = 182.655; // cm
      femc_rmin2 = 50.0; // cm - accomodate Mar 2020 EIC beam pipe
      femc_rmax2 = 182.655; // cm
      femc_dz = 36.5; // cm (FULL SIZE)

      /* Tower parameters */
      // From PHENIX EMCal JGL 12/27/2015
      tower_dx = 5.535; // cm
      tower_dy = 5.535; // cm
      tower_dz = 36.3; // cm (FULL SIZE)
    }
  else if ( setup == "FwdSquare_ROS" )
    {
      squarecutout = true;
      /* Global detector position / transformation */
      femc_x0 =  0.0; // cm,
      femc_y0 =  0.0; // cm,
      femc_z0 = 310.0; // cm,

      femc_rot_x0 =  0.0;
      femc_rot_y0 =  0.0;
      femc_rot_z0 =  0.0;

      /* Detector envelope size (cone shape) */
      femc_rmin1 = 50.0; // cm - accomodate Mar 2020 EIC beam pipe
      femc_rmax1 = 182.655; // cm
      femc_rmin2 = 50.0; // cm - accomodate Mar 2020 EIC beam pipe
      femc_rmax2 = 182.655; // cm
      femc_dz = 36.5; // cm (FULL SIZE)

      /* Tower parameters */
      // From PHENIX EMCal JGL 12/27/2015
      tower_dx = 5.535; // cm
      tower_dy = 5.535; // cm
      tower_dz = 36.3; // cm (FULL SIZE)
      tower_ROS = 3.;
    }
  else if ( setup == "EIC_v1" )
    {
      /* Global detector position / transformation */
      femc_x0 =  0.0; // cm,
      femc_y0 =  0.0; // cm,
      femc_z0 = 315.0; // cm,

      femc_rot_x0 =  0.0;
      femc_rot_y0 =  0.0;
      femc_rot_z0 =  0.0;

      /* Detector envelope size (cone shape) */
      femc_rmin1 = 11; // cm
      femc_rmax1 = 225; // cm
      femc_rmin2 = 12; // cm
      femc_rmax2 = 246; // cm
      femc_dz = 17; // cm

      /* Tower parameters */
      tower_dx = 3.0; // cm
      tower_dy = 3.0; // cm
      tower_dz = 17.0; // cm
    }

  // NOTE: code below assumes tower_dx = tower_dy
  // Will need to be updated if that's not the case JGL 12/27/2015
  unsigned n_towers_j = 2 * ( (unsigned)( (femc_rmax1/tower_dx) ));
  unsigned n_towers_k = 2 * ( (unsigned)( (femc_rmax1/tower_dx) ));

  double xpos_j0_k0 = (-1 * ( (double)( n_towers_j - 1 ) / 2 ) * tower_dx) + 0.5*tower_dx;
  double ypos_j0_k0 = (-1 * ( (double)( n_towers_j - 1 ) / 2 ) * tower_dx) + 0.5*tower_dx;

  cout << "n_towers_j = " << n_towers_j << endl;
  cout << "n_towers_k = " << n_towers_k << endl;
  cout << "xpos_j0_k0 = " << xpos_j0_k0 << endl;
  cout << "ypos_j0_k0 = " << ypos_j0_k0 << endl;

  // create map
  ofstream fout(Form("towerMap_FEMC_%s.txt",setup.Data()));

  /* Global detector transformation */
  fout << "#Global detector geometry and transforamtion; lengths given in cm" << endl;
  fout << "Gtype " << 2 << endl;
  fout << "Gr1_inner " << femc_rmin1 << endl;
  fout << "Gr1_outer " << femc_rmax1 << endl;
  fout << "Gr2_inner " << femc_rmin2 << endl;
  fout << "Gr2_outer " << femc_rmax2 << endl;
  fout << "Gdz " << femc_dz << endl;
  fout << "Gx0 " << femc_x0 << endl;
  fout << "Gy0 " << femc_y0 << endl;
  fout << "Gz0 " << femc_z0 << endl;
  fout << "Grot_x " << femc_rot_x0 << endl;
  fout << "Grot_y " << femc_rot_y0 << endl;
  fout << "Grot_z " << femc_rot_z0 << endl;
  fout << "Gtower2_dx " << tower_dx/tower_ROS << endl;
  fout << "Gtower2_dy " << tower_dy/tower_ROS << endl;
  fout << "Gtower2_dz " << tower_dz << endl;

  /* Tower mapping */
  fout << "#Tower type,idx_j,idx_k,idx_l,x[cm],y[cm],z[cm],dx[cm],dy[cm],dz[cm],rot_x,rot_y,rot_z" << endl;

  unsigned int twr_count = 0; 
  unsigned idx_l = 0;
  unsigned idtx_j = 0;
  unsigned idtx_k = 0;

  for (int idx_j = 0; idx_j < n_towers_j; idx_j++){
    for (int idx_k = 0; idx_k < n_towers_k; idx_k++){

      /* Calculate center position for tower */
      double xpos = xpos_j0_k0 + idx_j * tower_dx;
      double ypos = ypos_j0_k0 + idx_k * tower_dy;
      double zpos = 0;


      // check if all four corners are within envelope volume
      double r_corner_1 = sqrt( pow( xpos + tower_dx/2. , 2 ) + pow( ypos + tower_dy/2. , 2 ) );
      double r_corner_2 = sqrt( pow( xpos - tower_dx/2. , 2 ) + pow( ypos + tower_dy/2. , 2 ) );
      double r_corner_3 = sqrt( pow( xpos + tower_dx/2. , 2 ) + pow( ypos - tower_dy/2. , 2 ) );
      double r_corner_4 = sqrt( pow( xpos - tower_dx/2. , 2 ) + pow( ypos - tower_dy/2. , 2 ) );

      if ( r_corner_1 > femc_rmax1 ||
            r_corner_2 > femc_rmax1 ||
            r_corner_3 > femc_rmax1 ||
            r_corner_4 > femc_rmax1 )
        continue;

      if(squarecutout){
        double x_corner_1_offset = xpos - offset_rmin_x + tower_dx/2. ;
        double x_corner_2_offset = xpos - offset_rmin_x - tower_dx/2. ;
        double x_corner_3_offset = xpos - offset_rmin_x + tower_dx/2. ;
        double x_corner_4_offset = xpos - offset_rmin_x - tower_dx/2. ;
        double y_corner_1_offset = ypos + tower_dy/2.;
        double y_corner_2_offset = ypos + tower_dy/2.;
        double y_corner_3_offset = ypos - tower_dy/2.;
        double y_corner_4_offset = ypos - tower_dy/2.;
        if (  (abs(x_corner_1_offset) < femc_rmin1 && abs(y_corner_1_offset) < femc_rmin1) ||
              (abs(x_corner_2_offset) < femc_rmin1 && abs(y_corner_2_offset) < femc_rmin1) ||
              (abs(x_corner_3_offset) < femc_rmin1 && abs(y_corner_3_offset) < femc_rmin1) ||
              (abs(x_corner_4_offset) < femc_rmin1 && abs(y_corner_4_offset) < femc_rmin1) )
          continue;
      } else {
        double r_corner_1_offset = sqrt( pow( xpos - offset_rmin_x + tower_dx/2. , 2 ) + pow( ypos + tower_dy/2. , 2 ) );
        double r_corner_2_offset = sqrt( pow( xpos - offset_rmin_x - tower_dx/2. , 2 ) + pow( ypos + tower_dy/2. , 2 ) );
        double r_corner_3_offset = sqrt( pow( xpos - offset_rmin_x + tower_dx/2. , 2 ) + pow( ypos - tower_dy/2. , 2 ) );
        double r_corner_4_offset = sqrt( pow( xpos - offset_rmin_x - tower_dx/2. , 2 ) + pow( ypos - tower_dy/2. , 2 ) );
        if ( r_corner_1_offset < femc_rmin1 ||
              r_corner_2_offset < femc_rmin1 ||
              r_corner_3_offset < femc_rmin1 ||
              r_corner_4_offset < femc_rmin1 )
          continue;
      }

      if(tower_ROS==1){
        fout << "Tower " << 2 << " " << idx_j << " " << idx_k << " " << idx_l << " " << xpos << " " << ypos << " " << zpos << " " << tower_dx << " " << tower_dy << " " << tower_dz << " 0 0 0" << endl;
        twr_count++;
      } else {
        for(int isubj=0; isubj<tower_ROS; isubj++){
          idtx_j = idx_j*tower_ROS + isubj;
          float xpos_sub = (xpos-tower_dx/2) + isubj * (tower_dx/tower_ROS);

          for(int isubk=0; isubk<tower_ROS; isubk++){
            float ypos_sub = (ypos-tower_dy/2) + isubk * (tower_dy/tower_ROS);
            idtx_k = idx_k*tower_ROS + isubk;
            fout << "Tower " << 2 << " " << idtx_j << " " << idtx_k << " " << idx_l << " " << xpos_sub << " " << ypos_sub << " " << zpos << " " << tower_dx << " " << tower_dy << " " << tower_dz << " 0 0 0" << endl;
            twr_count++;
          }
        }
      }
    }
  }

  fout.close();

  cout << "Placed " << twr_count << " towers in mapping file." << endl; 

}
