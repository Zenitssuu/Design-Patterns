import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;

interface DocumentElement {
    public String render();
}

class TextElement implements DocumentElement {
    private String text;

    public TextElement(String text) {
        this.text = text;
    }

    @Override
    public String render() {
        return this.text;
    }
}

class ImageElement implements DocumentElement {
    private String image;

    public ImageElement(String image) {
        this.image = "[Image: " + image + " ]";
    }

    @Override
    public String render() {
        return this.image;
    }
}

class NewLineElement implements DocumentElement {
    private String line;
    public NewLineElement() {
        this.line = "\n";
    }
    @Override
    public String render() {
        return this.line;
    }
}

interface Storage{
    public void save(String data);
}

class SQLStorage implements Storage{
    @Override
    public void save(String data) {
        System.out.println("Stored in SQL storage");
    }
}

class NoSQLStorage implements Storage{
    @Override
    public void save(String data) {
        System.out.println("Stored in NoSQL storage");
    }
}

class FileStorage implements Storage{
    @Override
    public void save(String data) {
//        System.out.println(data);
        try{
            FileWriter fw = new FileWriter("document.txt");
            fw.write(data);
            fw.close();
            System.out.println("Document has been saved in file");
        }
        catch(Exception e){
            System.out.println("Error while saving document: "+e.getMessage());
        }
    }
}

class Document{
    private List<DocumentElement> elements = new ArrayList<DocumentElement>();

    public void addElement(DocumentElement element){
        this.elements.add(element);
    }

    public String renderDocument(){
        StringBuilder result = new StringBuilder();
        for(DocumentElement element : elements){
            result.append(element.render());
        }
        return result.toString();
    }
}

class DocumentEditor{
    private Document document;
    private Storage  storage;
    private String renderDoc;

    public DocumentEditor(Document document, Storage storage){
        this.document = document;
        this.storage = storage;
    }

    public void addText(String text){
        this.document.addElement(new TextElement(text));
    }

    public void addImage(String image){
        this.document.addElement(new ImageElement(image));
    }

    public void addNewLine(){
        this.document.addElement(new NewLineElement());
    }

    public String renderDocument(){
        this.renderDoc = this.document.renderDocument();
//        System.out.println(this.renderDoc);
        return renderDoc;
    }

    public void save(){
//        System.out.println(this.renderDoc);
        storage.save(this.renderDoc);
    }
}

public class Editor {
    public static void main(String[] args) {
        Document  document = new Document();
        Storage storage = new FileStorage();

        DocumentEditor editor = new DocumentEditor(document, storage);
        editor.addText("Hello World");
        editor.addNewLine();
        editor.addImage("Hello Image");
        editor.addNewLine();
        editor.addText("Welcome to my first project, A real world document editor");
        editor.addNewLine();
        editor.addImage("picture.jpg");

//        System.out.println("Document: "+document.renderDocument());
        System.out.println(editor.renderDocument());
        editor.save();
    }
}
