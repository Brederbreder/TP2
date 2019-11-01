package trinity;

import java.util.Scanner;

public class WordFrequencyController {
	private WordFrequenciesModel model;
	private WordFrequenciesView view;

	public WordFrequencyController(WordFrequenciesModel model, WordFrequenciesView view) {
		this.model = model;
		this.view  = view;
		view.render();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Next file: (Type 'END' to finish)" );
		String file = "";
		while (sc.hasNext()) {
			file = sc.next();
			if (file.equalsIgnoreCase("end")) break;
			this.model.freqs.clear();
			this.model.update(file);
			this.view.render();
			System.out.println("Next file: (Type 'END' to finish)");
		}
		sc.close();
	}
}
