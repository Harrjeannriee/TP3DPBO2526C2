public class TraditionalArtwork extends Artwork
{
    private String Medium;
    private String Size;

    // kalau mau bikin TraditionalArtwork, kasih 5 data ini
    public TraditionalArtwork(String ArtStyle, String CreationDate, String Price,
                              String Medium, String Size)
    {
        super(ArtStyle, CreationDate, Price); // panggil constructor milik parent (Artwork)

        this.Medium = Medium;
        this.Size = Size;
    }

    // Getter
    public String getMedium()
    {
        return this.Medium;
    }

    public String getSize()
    {
        return this.Size;
    }

    // Setter
    public void setMedium(String Medium)
    {
        this.Medium = Medium;
    }

    public void setSize(String Size)
    {
        this.Size = Size;
    }
}