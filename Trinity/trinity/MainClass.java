package trinity;


public class MainClass {

	public static void main(String[] args) {	
		WordFrequenciesModel m = new WordFrequenciesModel(args[0]);
		WordFrequenciesView v = new WordFrequenciesView(m);
		WordFrequencyController c = new WordFrequencyController(m, v);
		c.run();		
	}
}
