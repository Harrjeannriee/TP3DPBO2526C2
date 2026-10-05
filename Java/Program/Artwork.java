public class Artwork
{
    private String ArtStyle;
    private String CreationDate;
    private String Price;

    // Constructor
    public Artwork(String ArtStyle, String CreationDate, String Price)
    {
        this.ArtStyle = ArtStyle;
        this.CreationDate = CreationDate;
        this.Price = Price;
    }

    // Getter
    public String getArtStyle()
    {
        return this.ArtStyle;
    }
    public String getCreationDate()
    {
        return this.CreationDate;
    }
    public String getPrice()
    {
        return this.Price;
    }

    // Setter
    public void setArtStyle(String ArtStyle)
    {
        this.ArtStyle = ArtStyle;
    }
    public void setCreationDate(String CreationDate)
    {
        this.CreationDate = CreationDate;
    }
    public void setPrice(String Price)
    {
        this.Price = Price;
    }
}