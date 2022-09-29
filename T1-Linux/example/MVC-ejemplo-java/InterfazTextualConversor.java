import java.awt.event.ActionEvent;
import java.io.BufferedReader;
import java.io.InputStreamReader;
public class InterfazTextualConversor implements InterfazVista {
	private ControlConversor controlador;
	// Gestión de la entrada por teclado
	private BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private int leeOpción() {
		String s = null;
		try {
			s = in.readLine();
			return Integer.parseInt(s);
		} catch(Exception e){
		operaciónIncorrecta(); return 0;
		}
	}

private double leeCantidad() {
	String s = null;
	try {
		s = in.readLine();
		return Double.parseDouble(s);
	} catch(Exception e){
	System.out.println("Error en formato del número, tiene que ser 99.99: ");
	return leeCantidad();
	}
}

private void solicitaOperación() {
	System.out.println("Indica la operación que quiere realizar:");
	System.out.println("1: convertir pesetas a euros");
	System.out.println("2: convertir euros a pesetas");
	System.out.println("0: salir");
}
private void procesaNuevaOperacion() {
	int operacion;
	solicitaOperación();
	operacion = leeOpción();
	if ( operacion == 0 ) {
		System.out.println("Adiós.");
		System.exit(0);
	}
	if (operacion == 1 ) {
		controlador.actionPerformed( new ActionEvent(this, operacion, AEUROS) );
}	
	if (operacion == 2 ) {
		controlador.actionPerformed( new ActionEvent(this, operacion, APESETAS) );
	}
	operaciónIncorrecta();
}
private void operaciónIncorrecta() {
	System.out.print("Operación incorrecta. ");
	procesaNuevaOperacion();
}
// Métodos de la interfaz de la Vista:
public void setControlador(ControlConversor c) {
	controlador = c;
}
public void arranca() {
	procesaNuevaOperacion();
}
public void escribeCambio(String s) {
	// escribe el resultado:
	System.out.println(s);
	// y vuelve a solicitar al usuario una operación:
	procesaNuevaOperacion();
}
public double getCantidad() {
	System.out.print("Cantidad a convertir (formato 99.99): ");
	return leeCantidad();
}

}
