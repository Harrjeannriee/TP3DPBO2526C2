public class Client
{
    private int Id;
    private String Name;
    private String Email;
    private Commission commission;

    // Constructor
    public Client(int Id, String Name, String Email)
    {
        this.Id = Id;
        this.Name = Name;
        this.Email = Email;
        this.commission = null; // Saat client baru dibuat, dia belum punya commission
    }

    // Getter
    public int getId()
    {
        return this.Id;
    }
    public String getName()
    {
        return this.Name;
    }
    public String getEmail()
    {
        return this.Email;
    }

    // Setter
    public void setId(int Id)
    {
        this.Id = Id;
    }
    public void setName(String Name)
    {
        this.Name = Name;
    }
    public void setEmail(String Email)
    {
        this.Email = Email;
    }

    // Composition
    // Commission yang diberi ke fungsi ini jadi commission milik client ini
    public void addCommission(Commission Commission)
    {
        // Commission milik client diisi dengan commission yang diterima sebagai parameter
        this.commission = Commission;
    }

    // Getter Commission untuk mengambil commission dari client
    public Commission getCommission()
    {
        return this.commission;
    }
}