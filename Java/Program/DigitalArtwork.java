public class DigitalArtwork extends Artwork
{
    private String Resolution;
    private String FileFormat;

    // kalau mau bikin DigitalArtwork, kasih 5 data ini
    public DigitalArtwork(String ArtStyle, String CreationDate, String Price,
                          String Resolution, String FileFormat)
    {
        super(ArtStyle, CreationDate, Price); // panggil constructor milik parent (Artwork)

        this.Resolution = Resolution;
        this.FileFormat = FileFormat;
    }

    // Getter
    public String getResolution()
    {
        return this.Resolution;
    }
    public String getFileFormat()
    {
        return this.FileFormat;
    }

    // Setter
    public void setResolution(String Resolution)
    {
        this.Resolution = Resolution;
    }
    public void setFileFormat(String FileFormat)
    {
        this.FileFormat = FileFormat;
    }
}