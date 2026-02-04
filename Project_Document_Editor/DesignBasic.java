import java.util.ArrayList;
import java.util.List;

//Very basic design.

// here we just have one document editor class which has all the responsibility
// it has features:
//    -> add text element
//    -> add image element
//    -> render document
//    -> save document

// here client will directly interact with the class without any interface between them


class BasicEditor{
    private List<String> docElements = new ArrayList<String>();

    public void addText(String text){
        docElements.add(text);
    }
    public void addImage(String image){
        String ele = "[Image: "+image+"]";
        docElements.add(ele);
    }

    public String renderDocument(){
        String result = "";
        for(String docElement : docElements){
            result += docElement + "\n";
        }
        return result;
    }

    public void saveDocument(){
        System.out.println("\nSaving document...");
        System.out.println("Document: "+renderDocument());
        System.out.println("Document saved.");
    }
}

public class DesignBasic {
    public static void main(String[] args) {
        BasicEditor editor = new BasicEditor();
        editor.addText("Hello World");
        editor.addImage("Hello Image");
        System.out.println(editor.renderDocument());
        editor.saveDocument();
    }
}
