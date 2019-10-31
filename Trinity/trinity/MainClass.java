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


public class MainClass {

	public static void main(String[] args) {	
		WordFrequenciesModel m = new WordFrequenciesModel(args[0]);
		WordFrequenciesView v = new WordFrequenciesView(m);
		WordFrequencyController c = new WordFrequencyController(m, v);
		c.run();		
	}
}