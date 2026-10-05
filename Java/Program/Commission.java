public class Commission
{
    private int IdReq;
    private String Request;
    private String Deadline;
    private Artwork artwork;

    // Constructor, intinya kalau mau bikin sebuah Commission,
    // harus kasih IdReq, Request, Deadline
    public Commission(int IdReq, String Request, String Deadline)
    {
        this.IdReq = IdReq;
        this.Request = Request;
        this.Deadline = Deadline;
        this.artwork = null; // Saat commission baru dibuat, dia belum punya artwork
    }

    // Getter
    public int getIdreq()
    {
        return this.IdReq;
    }
    public String getRequest()
    {
        return this.Request;
    }
    public String getDeadline()
    {
        return this.Deadline;
    }

    // Setter
    public void setIdReq(int IdReq)
    {
        this.IdReq = IdReq;
    }
    public void setRequest(String Request)
    {
        this.Request = Request;
    }
    public void setDeadline(String Deadline)
    {
        this.Deadline = Deadline;
    }

    // Composition
    // (Bahasa bayi buat saya: Commission, nih ada artwork, simpan artwork ini di gue ya)
    public void addArtwork(Artwork Artwork)
    {
        this.artwork = Artwork;
    }

    // Getter Artwork
    public Artwork getArtwork()
    {
        return this.artwork;
    }
}