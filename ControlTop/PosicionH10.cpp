#include "PosicionH10.h"
#include "rtwtypes.h"
#include "mldivide_l89k28gF.h"
#include <cmath>
#include "look2_binlcpw.h"
#include "PosicionH10_private.h"

void PosicionH10::init(void)
{
  PosicionH10_DW.Z_DSTATE[0] = 0.025;
  PosicionH10_DW.Z_DSTATE[1] = 0.0;
  PosicionH10_DW.Z_DSTATE[2] = 9.8;
}

void PosicionH10::step0(void)
{
}

void PosicionH10::step1(const real_T rtu_airgaps_sensores[8], const real_T
  *rtu_RefZ, const real_T rtu_I_HEMS[4], real_T rty_GapsLoclaes[4], real_T
  rty_I_referencia[4], real_T rty_Pos[5])
{
  real_T tmp[4];
  real_T q[3];
  real_T rtb_Kin_HEMS[3];
  real_T rotx;
  real_T rotz;
  real_T rtb_Kin_HEMS_0;
  real_T rtb_Kin_HEMS_1;
  real_T rtb_Kin_HEMS_2;
  real_T tmp_0;
  real_T tmp_1;
  int32_T i;
  static const real_T b[12]{ 1.0, 1.0, 1.0, 1.0, -0.31417, 0.24811, -0.31417,
    0.24811, -1.24708, -1.24946, 1.27493, 1.27253 };

  real_T rtb_Kin_HEMS_tmp;
  real_T rtb_Kin_HEMS_tmp_0;
  real_T tmp_2;
  tmp[0] = 0.11965 - rtu_airgaps_sensores[0];
  tmp[1] = 0.11965 - rtu_airgaps_sensores[1];
  tmp[2] = 0.11965 - rtu_airgaps_sensores[2];
  tmp[3] = 0.11965 - rtu_airgaps_sensores[3];
  mldivide_l89k28gF(b, tmp, q);
  rotx = std::asin(std::fmin(1.0, std::fmax(-1.0, q[1])));
  rotz = (std::asin(std::fmin(1.0, std::fmax(-1.0, (rtu_airgaps_sensores[4] -
              rtu_airgaps_sensores[6]) / 2.55205))) + std::asin(std::fmin(1.0,
            std::fmax(-1.0, (rtu_airgaps_sensores[7] - rtu_airgaps_sensores[5]) /
                      2.55205)))) / 2.0;
  rtb_Kin_HEMS_0 = 0.2877 * std::cos(rotz);
  rtb_Kin_HEMS_1 = 1.276025 * std::sin(rotz);
  rtb_Kin_HEMS_2 = 0.186484 * std::sin(rotx);
  rty_Pos[0] = (((((((rtu_airgaps_sensores[4] - 0.3592) + rtb_Kin_HEMS_0) -
                    rtb_Kin_HEMS_1) + rtb_Kin_HEMS_2) +
                  ((((-rtu_airgaps_sensores[5] + 0.3592) - rtb_Kin_HEMS_0) -
                    rtb_Kin_HEMS_1) + rtb_Kin_HEMS_2)) +
                 ((((rtu_airgaps_sensores[6] - 0.3592) + rtb_Kin_HEMS_0) +
                   rtb_Kin_HEMS_1) + rtb_Kin_HEMS_2)) +
                ((((-rtu_airgaps_sensores[7] + 0.3592) - rtb_Kin_HEMS_0) +
                  rtb_Kin_HEMS_1) + rtb_Kin_HEMS_2)) / 4.0;
  rty_Pos[1] = q[0];
  rty_Pos[2] = rotx;
  rty_Pos[3] = std::asin(std::fmin(1.0, std::fmax(-1.0, q[2])));
  rty_Pos[4] = rotz;
  rty_GapsLoclaes[0] = std::abs((rty_Pos[1] - 0.28958 * std::sin(rty_Pos[2])) -
    0.76978 * std::sin(rty_Pos[3]));
  rty_GapsLoclaes[1] = std::abs((0.22351 * std::sin(rty_Pos[2]) + rty_Pos[1]) -
    0.76978 * std::sin(rty_Pos[3]));
  rty_GapsLoclaes[2] = std::abs((rty_Pos[1] - 0.28958 * std::sin(rty_Pos[2])) +
    0.79522 * std::sin(rty_Pos[3]));
  rty_GapsLoclaes[3] = std::abs((0.22351 * std::sin(rty_Pos[2]) + rty_Pos[1]) +
    0.79522 * std::sin(rty_Pos[3]));
  q[0] = PosicionH10_DW.uz_DSTATE[0];
  q[1] = PosicionH10_DW.uz_DSTATE[1];
  q[2] = PosicionH10_DW.uz_DSTATE[2];

  {
    rtb_Kin_HEMS[0] = 0.9151416593531595*PosicionH10_DW.Z_DSTATE[0] +
      0.00045757082967659378*PosicionH10_DW.Z_DSTATE[1]
      + 2.2878541483830569E-7*PosicionH10_DW.Z_DSTATE[2];
    rtb_Kin_HEMS[0] += 0.084858340646840488*rty_Pos[1] +
      (-7.9692389653852942E-10)*PosicionH10_DW.uz_DSTATE[0];
    rtb_Kin_HEMS[1] = (-4.9911826101121326)*PosicionH10_DW.Z_DSTATE[0] +
      0.99750440869494383*PosicionH10_DW.Z_DSTATE[1]
      + 0.000498752204347472*PosicionH10_DW.Z_DSTATE[2];
    rtb_Kin_HEMS[1] += 4.9911826101121326*rty_Pos[1] + (-1.7372940944539445E-6)*
      PosicionH10_DW.uz_DSTATE[0];
    rtb_Kin_HEMS[2] = (-98.83529921014123)*PosicionH10_DW.Z_DSTATE[0] +
      (-0.049417649605073846)*PosicionH10_DW.Z_DSTATE[1]
      + 0.99997529117519768*PosicionH10_DW.Z_DSTATE[2];
    rtb_Kin_HEMS[2] += 98.83529921014123*rty_Pos[1] + 8.6067780826161244E-8*
      PosicionH10_DW.uz_DSTATE[0];
  }

  rotx = (((*rtu_RefZ - rtb_Kin_HEMS[0]) * 625.0 - 50.0 * rtb_Kin_HEMS[1]) -
          rtb_Kin_HEMS[2]) * -287.08565;

  {
    rtb_Kin_HEMS[0] = 0.9151416593531595*PosicionH10_DW.Roll_DSTATE[0] +
      0.00045757082967659378*PosicionH10_DW.Roll_DSTATE[1]
      + 2.2878541483830569E-7*PosicionH10_DW.Roll_DSTATE[2];
    rtb_Kin_HEMS[0] += 0.084858340646840488*rty_Pos[2] + (-1.5828508778415032E-9)*
      PosicionH10_DW.uz_DSTATE[1];
    rtb_Kin_HEMS[1] = (-4.9911826101121326)*PosicionH10_DW.Roll_DSTATE[0] +
      0.99750440869494383*PosicionH10_DW.Roll_DSTATE[1]
      + 0.000498752204347472*PosicionH10_DW.Roll_DSTATE[2];
    rtb_Kin_HEMS[1] += 4.9911826101121326*rty_Pos[2] + (-3.4506149136944008E-6)*
      PosicionH10_DW.uz_DSTATE[1];
    rtb_Kin_HEMS[2] = (-98.83529921014123)*PosicionH10_DW.Roll_DSTATE[0] +
      (-0.049417649605073846)*PosicionH10_DW.Roll_DSTATE[1]
      + 0.99997529117519768*PosicionH10_DW.Roll_DSTATE[2];
    rtb_Kin_HEMS[2] += 98.83529921014123*rty_Pos[2] + 1.7094789480688236E-7*
      PosicionH10_DW.uz_DSTATE[1];
  }

  rotz = (((0.0 - rtb_Kin_HEMS[0]) * 900.0 - 60.0 * rtb_Kin_HEMS[1]) -
          rtb_Kin_HEMS[2]) * -144.54009410557;

  {
    rtb_Kin_HEMS[0] = 0.87629660405490917*PosicionH10_DW.Pitch_DSTATE[0] +
      0.000438148302027456*PosicionH10_DW.Pitch_DSTATE[1]
      + 2.1907415101372875E-7*PosicionH10_DW.Pitch_DSTATE[2];
    rtb_Kin_HEMS[0] += 0.12370339594509094*rty_Pos[3] + (-9.89446932676578E-9)*
      PosicionH10_DW.uz_DSTATE[2];
    rtb_Kin_HEMS[1] = (-10.806708795356153)*PosicionH10_DW.Pitch_DSTATE[0] +
      0.99459664560232186*PosicionH10_DW.Pitch_DSTATE[1]
      + 0.00049729832280116109*PosicionH10_DW.Pitch_DSTATE[2];
    rtb_Kin_HEMS[1] += 10.806708795356153*rty_Pos[3] + (-2.2460445371758375E-5)*
      PosicionH10_DW.uz_DSTATE[2];
    rtb_Kin_HEMS[2] = (-319.41011217801451)*PosicionH10_DW.Pitch_DSTATE[0] +
      (-0.15970505608900332)*PosicionH10_DW.Pitch_DSTATE[1]
      + 0.99992014747195579*PosicionH10_DW.Pitch_DSTATE[2];
    rtb_Kin_HEMS[2] += 319.41011217801446*rty_Pos[3] + 3.6065340696060982E-6*
      PosicionH10_DW.uz_DSTATE[2];
  }

  rtb_Kin_HEMS[2] = (((0.0 - rtb_Kin_HEMS[0]) * 1225.0 - 70.0 * rtb_Kin_HEMS[1])
                     - rtb_Kin_HEMS[2]) * -22.1410713176;
  rtb_Kin_HEMS_0 = 1000.0 * rty_GapsLoclaes[0];
  rtb_Kin_HEMS_tmp = 0.3194888178913738 * rtb_Kin_HEMS[2];
  rtb_Kin_HEMS_tmp_0 = 0.9744879066050791 * rotz;
  rtb_Kin_HEMS_1 = look2_binlcpw(rtb_Kin_HEMS_0, (-0.2218716897688795 * rotx +
    rtb_Kin_HEMS_tmp_0) + rtb_Kin_HEMS_tmp, rtCP_InvLUT_1_bp01Data,
    rtCP_InvLUT_1_bp02Data, rtCP_InvLUT_1_tableData, rtCP_InvLUT_1_maxIndex, 54U);
  rtb_Kin_HEMS_2 = 1000.0 * rty_GapsLoclaes[1];
  rotz *= -0.9744879066050791;
  rtb_Kin_HEMS_tmp = look2_binlcpw(rtb_Kin_HEMS_2, (-0.2862561057582771 * rotx +
    rotz) + rtb_Kin_HEMS_tmp, rtCP_InvLUT_2_bp01Data, rtCP_InvLUT_2_bp02Data,
    rtCP_InvLUT_2_tableData, rtCP_InvLUT_2_maxIndex, 54U);
  tmp_0 = 1000.0 * rty_GapsLoclaes[2];
  tmp_2 = -0.3194888178913738 * rtb_Kin_HEMS[2];
  rtb_Kin_HEMS_tmp_0 = look2_binlcpw(tmp_0, (-0.21374389424172294 * rotx +
    rtb_Kin_HEMS_tmp_0) + tmp_2, rtCP_InvLUT_3_bp01Data, rtCP_InvLUT_3_bp02Data,
    rtCP_InvLUT_3_tableData, rtCP_InvLUT_3_maxIndex, 54U);
  tmp_1 = 1000.0 * rty_GapsLoclaes[3];
  rotx = look2_binlcpw(tmp_1, (-0.2781283102311205 * rotx + rotz) + tmp_2,
                       rtCP_InvLUT_4_bp01Data, rtCP_InvLUT_4_bp02Data,
                       rtCP_InvLUT_4_tableData, rtCP_InvLUT_4_maxIndex, 54U);
  if (rtb_Kin_HEMS_1 > 45.0) {
    rty_I_referencia[0] = 45.0;
  } else if (rtb_Kin_HEMS_1 < -45.0) {
    rty_I_referencia[0] = -45.0;
  } else {
    rty_I_referencia[0] = rtb_Kin_HEMS_1;
  }

  if (rtb_Kin_HEMS_tmp > 45.0) {
    rty_I_referencia[1] = 45.0;
  } else if (rtb_Kin_HEMS_tmp < -45.0) {
    rty_I_referencia[1] = -45.0;
  } else {
    rty_I_referencia[1] = rtb_Kin_HEMS_tmp;
  }

  if (rtb_Kin_HEMS_tmp_0 > 45.0) {
    rty_I_referencia[2] = 45.0;
  } else if (rtb_Kin_HEMS_tmp_0 < -45.0) {
    rty_I_referencia[2] = -45.0;
  } else {
    rty_I_referencia[2] = rtb_Kin_HEMS_tmp_0;
  }

  if (rotx > 45.0) {
    rty_I_referencia[3] = 45.0;
  } else if (rotx < -45.0) {
    rty_I_referencia[3] = -45.0;
  } else {
    rty_I_referencia[3] = rotx;
  }

  rtb_Kin_HEMS_1 = look2_binlcpw(rtb_Kin_HEMS_0, rtu_I_HEMS[0],
    rtCP_LUT_HEMS_1_bp01Data, rtCP_LUT_HEMS_1_bp02Data,
    rtCP_LUT_HEMS_1_tableData, rtCP_LUT_HEMS_1_maxIndex, 54U);
  rtb_Kin_HEMS_tmp = look2_binlcpw(rtb_Kin_HEMS_2, rtu_I_HEMS[1],
    rtCP_LUT_HEMS_2_bp01Data, rtCP_LUT_HEMS_2_bp02Data,
    rtCP_LUT_HEMS_2_tableData, rtCP_LUT_HEMS_2_maxIndex, 54U);
  rtb_Kin_HEMS_tmp_0 = look2_binlcpw(tmp_0, rtu_I_HEMS[2],
    rtCP_LUT_HEMS_3_bp01Data, rtCP_LUT_HEMS_3_bp02Data,
    rtCP_LUT_HEMS_3_tableData, rtCP_LUT_HEMS_3_maxIndex, 54U);
  rotx = look2_binlcpw(tmp_1, rtu_I_HEMS[3], rtCP_LUT_HEMS_4_bp01Data,
                       rtCP_LUT_HEMS_4_bp02Data, rtCP_LUT_HEMS_4_tableData,
                       rtCP_LUT_HEMS_4_maxIndex, 54U);
  for (i = 0; i < 3; i++) {
    PosicionH10_DW.uz_DSTATE[i] = ((rtCP_Kin_HEMS_Gain[i + 3] * rtb_Kin_HEMS_tmp
      + rtCP_Kin_HEMS_Gain[i] * rtb_Kin_HEMS_1) + rtCP_Kin_HEMS_Gain[i + 6] *
      rtb_Kin_HEMS_tmp_0) + rtCP_Kin_HEMS_Gain[i + 9] * rotx;
  }

  {
    real_T xnew[3];
    xnew[0] = 0.83028331870631911*PosicionH10_DW.Z_DSTATE[0] +
      0.00091514165935316794*PosicionH10_DW.Z_DSTATE[1]
      + 4.5757082967659735E-7*PosicionH10_DW.Z_DSTATE[2];
    xnew[0] += 0.16971668129368098*rty_Pos[1] + (-1.5938477930770588E-9)*q[0];
    xnew[1] = (-9.9823652202242652)*PosicionH10_DW.Z_DSTATE[0] +
      0.99500881738988789*PosicionH10_DW.Z_DSTATE[1]
      + 0.000997504408694944*PosicionH10_DW.Z_DSTATE[2];
    xnew[1] += 9.9823652202242652*rty_Pos[1] + (-3.474588188907889E-6)*q[0];
    xnew[2] = (-197.67059842028246)*PosicionH10_DW.Z_DSTATE[0] +
      (-0.098835299210142877)*PosicionH10_DW.Z_DSTATE[1]
      + 0.99995058235039513*PosicionH10_DW.Z_DSTATE[2];
    xnew[2] += 197.67059842028246*rty_Pos[1] + 1.7213556165232249E-7*q[0];
    (void) std::memcpy(PosicionH10_DW.Z_DSTATE, xnew,
                       sizeof(real_T)*3);
  }

  {
    real_T xnew[3];
    xnew[0] = 0.83028331870631911*PosicionH10_DW.Roll_DSTATE[0] +
      0.00091514165935316794*PosicionH10_DW.Roll_DSTATE[1]
      + 4.5757082967659735E-7*PosicionH10_DW.Roll_DSTATE[2];
    xnew[0] += 0.16971668129368098*rty_Pos[2] + (-3.1657017556830063E-9)*q[1];
    xnew[1] = (-9.9823652202242652)*PosicionH10_DW.Roll_DSTATE[0] +
      0.99500881738988789*PosicionH10_DW.Roll_DSTATE[1]
      + 0.000997504408694944*PosicionH10_DW.Roll_DSTATE[2];
    xnew[1] += 9.9823652202242652*rty_Pos[2] + (-6.9012298273888017E-6)*q[1];
    xnew[2] = (-197.67059842028246)*PosicionH10_DW.Roll_DSTATE[0] +
      (-0.098835299210142877)*PosicionH10_DW.Roll_DSTATE[1]
      + 0.99995058235039513*PosicionH10_DW.Roll_DSTATE[2];
    xnew[2] += 197.67059842028246*rty_Pos[2] + 3.4189578961376471E-7*q[1];
    (void) std::memcpy(PosicionH10_DW.Roll_DSTATE, xnew,
                       sizeof(real_T)*3);
  }

  {
    real_T xnew[3];
    xnew[0] = 0.75259320810981811*PosicionH10_DW.Pitch_DSTATE[0] +
      0.000876296604054912*PosicionH10_DW.Pitch_DSTATE[1]
      + 4.3814830202746851E-7*PosicionH10_DW.Pitch_DSTATE[2];
    xnew[0] += 0.24740679189018189*rty_Pos[3] + (-1.9788938653531559E-8)*q[2];
    xnew[1] = (-21.613417590712306)*PosicionH10_DW.Pitch_DSTATE[0] +
      0.98919329120464383*PosicionH10_DW.Pitch_DSTATE[1]
      + 0.000994596645602322*PosicionH10_DW.Pitch_DSTATE[2];
    xnew[1] += 21.613417590712306*rty_Pos[3] + (-4.4920890743516751E-5)*q[2];
    xnew[2] = (-638.82022435602892)*PosicionH10_DW.Pitch_DSTATE[0] +
      (-0.31941011217801363)*PosicionH10_DW.Pitch_DSTATE[1]
      + 0.99984029494391125*PosicionH10_DW.Pitch_DSTATE[2];
    xnew[2] += 638.82022435602892*rty_Pos[3] + 7.2130681392121963E-6*q[2];
    (void) std::memcpy(PosicionH10_DW.Pitch_DSTATE, xnew,
                       sizeof(real_T)*3);
  }
}

const char_T* PosicionH10::RT_MODEL_PosicionH10_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void PosicionH10::RT_MODEL_PosicionH10_T::setErrorStatus(const char_T* const
  aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

const char_T** PosicionH10::RT_MODEL_PosicionH10_T::getErrorStatusPointer()
  const
{
  return errorStatus;
}

void PosicionH10::RT_MODEL_PosicionH10_T::setErrorStatusPointer(const char_T
  ** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

PosicionH10::PosicionH10() :
  PosicionH10_DW(),
  PosicionH10_M()
{
}

PosicionH10::~PosicionH10() = default;
PosicionH10::RT_MODEL_PosicionH10_T * PosicionH10::getRTM()
{
  return (&PosicionH10_M);
}
