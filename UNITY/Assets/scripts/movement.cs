using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class movement : MonoBehaviour {
	public float AmountToMove;
	SerialPort Serial= new SerialPort ("COM6",9600);


	void Update () {
		if(!Serial.IsOpen)
			Serial.Open();

		float maindata = float.Parse (Serial.ReadLine());

		if (maindata == 1) {


			float data = float.Parse (Serial.ReadLine ());

			if (data > 400) {
				transform.Rotate (Vector3.down * AmountToMove, Space.World);
			}
			if (data < -200) {
				transform.Rotate (Vector3.up * AmountToMove, Space.World);
			}

		}

		if (maindata == 2) {

			float data1 = float.Parse (Serial.ReadLine ());

			if (data1<-400) {
				transform.Translate (Vector3.back * AmountToMove, Space.World);
			}
			if (data1 >400) {
				transform.Translate (Vector3.forward * AmountToMove, Space.World);
			}
		
		
		
		
		
		
		}

		}



}

