package trinity;

import java.awt.Desktop;
import java.io.File;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List; 
import java.util.Scanner;
import java.io.*;
import java.lang.*;
import java.util.*;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Iterator;
import java.util.Set;

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
			this.model.update(file);
			this.view.render();
			System.out.println("Next file: ");
		}
		sc.close();
	}
}
