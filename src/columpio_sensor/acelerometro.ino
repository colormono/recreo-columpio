/**
    METODOS PARA EL ACELEROMETRO

    La dirección del MPU6050 puede ser 0x68 o 0x69, dependiendo
    del estado de AD0. Si no se especifica, 0x68 estará implicito

    ax, ay, az y gx, gy, gz son los valores RAW (sin procesar)
    del acelerometro y giroscopio en los ejes x,y,z
*/

float getAccData() {

  // Leer las aceleraciones
  sensor.getAcceleration(&ax, &ay, &az);
  float ax_m_s2 = ax * (9.81 / 16384.0);
  float ay_m_s2 = ay * (9.81 / 16384.0);
  float az_m_s2 = az * (9.81 / 16384.0);

  //Mostrar las lecturas separadas por un [tab]
  Serial.print("a[x y z](m/s2):\t");
  Serial.print(ax_m_s2); Serial.print("\t");
  Serial.print(ay_m_s2); Serial.print("\t");
  Serial.println(az_m_s2);

  return ax_m_s2;
}


void getSensorData() {

  // Leer las aceleraciones y velocidades angulares
  sensor.getAcceleration(&ax, &ay, &az);
  sensor.getRotation(&gx, &gy, &gz);
  float ax_m_s2 = ax * (9.81 / 16384.0);
  float ay_m_s2 = ay * (9.81 / 16384.0);
  float az_m_s2 = az * (9.81 / 16384.0);
  float gx_deg_s = gx * (250.0 / 32768.0);
  float gy_deg_s = gy * (250.0 / 32768.0);
  float gz_deg_s = gz * (250.0 / 32768.0);

  //Mostrar las lecturas separadas por un [tab]
  Serial.print("a[x y z](m/s2) g[x y z](deg/s):\t");
  Serial.print(ax_m_s2); Serial.print("\t");
  Serial.print(ay_m_s2); Serial.print("\t");
  Serial.print(az_m_s2); Serial.print("\t");
  Serial.print(gx_deg_s); Serial.print("\t");
  Serial.print(gy_deg_s); Serial.print("\t");
  Serial.println(gz_deg_s);

  delay(100);
}


