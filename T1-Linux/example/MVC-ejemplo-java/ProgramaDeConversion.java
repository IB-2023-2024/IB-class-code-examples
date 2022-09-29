import java.awt.*;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;


/*
public class ConversorEurosPesetas { // Adaptador de objetos
  private ConversorEuros conversor;
  public ConversorEurosPesetas () {
	Conversor = new ConversorEuros(166.386D);
  }
  public double eurosApesetas(double cantidad) {
	return conversor.eurosAmoneda(cantidad);
  }
  public double pesetasAeuros(double cantidad) {
	return conversor.monedaAeuros(cantidad);
  }
}

*/

public class ProgramaDeConversion {
	public static void main(String[] args) {
		// el modelo:
		ConversorEurosPesetas modelo = new ConversorEurosPesetas();
		// la vista:
		// InterfazVista vista = new VentanaConversor();
		InterfazVista vista = new InterfazTextualConversor();
		// y el control:
		ControlConversor control = new ControlConversor (vista, modelo);
		// configura la vista
		vista.setControlador(control);
		// y arranca la interfaz (vista):
		vista.arranca();
	}
}




