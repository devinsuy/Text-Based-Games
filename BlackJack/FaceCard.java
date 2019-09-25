public class FaceCard extends Card {
    private String faceType;

    public FaceCard(int v, int s, String face){
        super(v, s);
        faceType = face;
        isFace = true;
    }

    public String getFaceType() {
        return faceType;
    }
}
