
int main(){
	
	/*
	Allgemein geschrieben:

	While Schleife mit dem wichtigem Logik Code!
   
  
  while (1)
  {

	  GPIO_PinState e, a;
	  e = HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin);
	  if (e == GPIO_PIN_RESET)
		  a = GPIO_PIN_SET;
	  else
		  a = GPIO_PIN_RESET;

	  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, a);
    
*/


    while (1)
{
    /* 1. Kontrollausgabe: Schalterzustand direkt an Verstärker-LEDs (Tabelle 3) */
    /* Liest den Pin vom Schalter und schreibt ihn direkt auf die zugehörige LED[span_2](end_span) */
   

Write(Port, pin, Read(Port, Pin))


   	//Schalter 1 
	HAL_GPIO_ReadPin(X1_GPIO_Port, X1_Pin);
	HAL_GPIO_WritePin(LV1_GPIO_Port, LV1_Pin,HAL_GPIO_ReadPin(X1_GPIO_Port, X1_Pin));
	//Schalter 2
	HAL_GPIO_ReadPin(X2_GPIO_Port, X2_Pin);
   	HAL_GPIO_WritePin(LV2_GPIO_Port, LV2_Pin);
	//Schalter 3
	HAL_GPIO_ReadPin(X3_GPIO_Port, X3_Pin);
  	HAL_GPIO_WritePin(LV3_GPIO_Port, LV3_Pin);
	//Schalter 4
	HAL_GPIO_ReadPin(X4_GPIO_Port, X4_Pin)
   	HAL_GPIO_WritePin(LV4_GPIO_Port, LV4_Pin);

    /* 2. Logik für die Onboard-LED Y (Tabelle 5) */
    
	/* Hinweis: Taster (X5, X6) liefern beim Drücken RESET (0), sollen laut Tabelle aber als '1' zählen[span_3](end_span)[span_4](end_span) */
    
	
	
 	// FALL 1: Weder SW1 noch SW2 gedrückt (Tabelle: X5=0, X6=0) -> LED AUS[span_5](end_span)
    if (HAL_GPIO_ReadPin(X5_GPIO_Port, X5_Pin) == GPIO_PIN_SET && 
        HAL_GPIO_ReadPin(X6_GPIO_Port, X6_Pin) == GPIO_PIN_SET) 
    {
        HAL_GPIO_WritePin(Y_GPIO_Port, Y_Pin, GPIO_PIN_RESET);
    }



	// FALL 2: Nur SW2 (X6) gedrückt -> LED AN, wenn mindestens ein Schalter AN ist (ODER)[span_6](end_span)
    else if (HAL_GPIO_ReadPin(X5_GPIO_Port, X5_Pin) == GPIO_PIN_SET && 
             HAL_GPIO_ReadPin(X6_GPIO_Port, X6_Pin) == GPIO_PIN_RESET) 
    {
        if (HAL_GPIO_ReadPin(X1_GPIO_Port, X1_Pin) == GPIO_PIN_SET ||
            HAL_GPIO_ReadPin(X2_GPIO_Port, X2_Pin) == GPIO_PIN_SET ||
            HAL_GPIO_ReadPin(X3_GPIO_Port, X3_Pin) == GPIO_PIN_SET ||
            HAL_GPIO_ReadPin(X4_GPIO_Port, X4_Pin) == GPIO_PIN_SET) 
        {
            HAL_GPIO_WritePin(Y_GPIO_Port, Y_Pin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(Y_GPIO_Port, Y_Pin, GPIO_PIN_RESET);
        }
    }



	// FALL 3: Nur SW1 (X5) gedrückt -> LED AN, wenn ALLE Schalter AN sind (UND)[span_7](end_span)
    else if (HAL_GPIO_ReadPin(X5_GPIO_Port, X5_Pin) == GPIO_PIN_RESET && 
             HAL_GPIO_ReadPin(X6_GPIO_Port, X6_Pin) == GPIO_PIN_SET) 
    {
        if (HAL_GPIO_ReadPin(X1_GPIO_Port, X1_Pin) == GPIO_PIN_SET &&
            HAL_GPIO_ReadPin(X2_GPIO_Port, X2_Pin) == GPIO_PIN_SET &&
            HAL_GPIO_ReadPin(X3_GPIO_Port, X3_Pin) == GPIO_PIN_SET &&
            HAL_GPIO_ReadPin(X4_GPIO_Port, X4_Pin) == GPIO_PIN_SET) 
        {
            HAL_GPIO_WritePin(Y_GPIO_Port, Y_Pin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(Y_GPIO_Port, Y_Pin, GPIO_PIN_RESET);
        }
    }



	// FALL 4: Beide Taster (X5 & X6) gedrückt -> XOR Logik zwischen X1 und X4[span_8](end_span)
    else if (HAL_GPIO_ReadPin(X5_GPIO_Port, X5_Pin) == GPIO_PIN_RESET && 
             HAL_GPIO_ReadPin(X6_GPIO_Port, X6_Pin) == GPIO_PIN_RESET) 
    {
        // Prüfen ob X1 und X4 unterschiedliche Zustände haben
        if (HAL_GPIO_ReadPin(X1_GPIO_Port, X1_Pin) != HAL_GPIO_ReadPin(X4_GPIO_Port, X4_Pin)) 
        {
            HAL_GPIO_WritePin(Y_GPIO_Port, Y_Pin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(Y_GPIO_Port, Y_Pin, GPIO_PIN_RESET);
        }
    }

    /* USER CODE END WHILE */
}




    return 0

}
