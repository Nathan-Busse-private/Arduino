
float floatMap(float x, float inMin, float inMax, float outMin, float outMax) 
{
  return (x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

void SendBeatData(bool stream,int reading)
{
	if (stream)
    {
      String Value;
      Value = "sr" + String(floatMap(reading, 0, 1024, 0, 5), 2);
      Serial.println(Value);
      delay(90);
    }
}

void SendBPM(bool stream,float BPM)
{
	if (stream)
    {
      String Value1;
      Value1 = "s\nb";
      Value1 += BPM;
      Serial.println(Value1);
    }
}

