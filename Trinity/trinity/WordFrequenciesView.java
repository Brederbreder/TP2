package trinity;

import java.util.Comparator;
import java.util.LinkedHashMap;
import java.util.Map;

public class WordFrequenciesView {
	private WordFrequenciesModel model;

	public WordFrequenciesView(WordFrequenciesModel model) {
		
		this.model = model;
	}

	public void render() { 
		LinkedHashMap<String, Integer> sorted_freqs = new LinkedHashMap<>();

		this.model.freqs
			.entrySet()
			.stream()
			.sorted(Map.Entry.comparingByValue(Comparator.reverseOrder())) 
			.forEachOrdered(x -> sorted_freqs.put(x.getKey(), x.getValue()));

		int count = 0; 
		printloop:
		for (Map.Entry<String, Integer> entry : sorted_freqs.entrySet()) {
    		count++;
    		System.out.println("'" + entry.getKey() + "'" + ": " + entry.getValue().toString());
			
			if (count == 30)
				break printloop;
		}
	}

}
